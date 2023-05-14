#include <iostream>
#include <vector>
#include <cstdlib>
#include "person.hpp"
#include "elevator.hpp"
using namespace std;

void PushPeople(PeopleArray &peopleArray, Person &person)
{
    int i = peopleArray.P.size();
    // 将person的地址放入peopleArray中
    peopleArray.P.push_back(&person);
}

// 初始化id
void Elev::setID(string id)
{
    this->id = id; // 这里用this->id是为了区分局部变量id和成员变量id
    // 因为this是指向当前对象的指针，所以this只能用->来访问成员变量，而不能用.来访问成员变量
}

// 访问id
string Elev::getID()
{
    return id;
}

// 设置方向
void Elev::setDirection(int direction)
{
    currentDirection = direction;
    // 1为上 -1为下
}

// 访问方向
string Elev::getDirection()
{
    if (currentDirection == 1)
    {
        return "上升";
    }
    else if (currentDirection == -1)
    {
        return "下降";
    }
    else
    {
        return "空载";
    }
}

// 设置新的方向
void Elev::setNewDirection()
{
    // 如果目标楼层队列为空
    if (destinations.empty())
    {
        // 如果电梯不在第一层，则方向为下降
        if (currentFloor != 1)
            currentDirection = -1;
        // 如果电梯在第一层，则方向为空载
        else
            currentDirection = 0;
    }
    // 如果目标楼层不为空，由目标楼层的第一个楼层决定方向
    else
    {
        if (destinations.front() > currentFloor)
        {
            currentDirection = 1;
        }
        else
        {
            currentDirection = -1;
        }
    }
}

// 上升楼层
void Elev::UpFloor()
{
    if (currentFloor < 40)
    {
        currentFloor++;
    }
}

// 下降楼层
void Elev::DownFloor()
{
    if (currentFloor > 1)
    {
        currentFloor--;
    }
}

// 获取当前楼层
int Elev::getFloor()
{
    return currentFloor;
}

// 初始化目标楼层
void Elev::setDestinationFloor()
{
    for (int i = 0; i <= 40; i++)
    {
        destinationFloor[i] = 0;
    }
}

// 刷新每个乘客的当前楼层
void Elev::refreshFloor()
{
    for (int i = 0; i < currentPeople; i++)
    {
        (peopleArray.P[i])->setCurrentFloor(currentFloor);
    }
}

// 添加目标楼层
void Elev::addDestination(int destination)
{
    // 目标楼层队列中有该楼层，不做任何操作
    if (destinationFloor[destination] == 1)
    {
        return;
    }
    // 如果目标楼层队列中没有该楼层，则将该楼层加入目标楼层队列
    else
    {
        destinations.push_back(destination);
        destinationFloor[destination] = 1;
    }
}

// 添加乘客
void Elev::AddPeople(Person &person)
{
    // 如果电梯在乘客所在楼层且人数未满，则将乘客加入电梯
    if (currentFloor == person.getCurrentFloor() && currentPeople < maxPeople)
    {
        // people.push_back(person);
        PushPeople(peopleArray, person);
        person.isinFlag = 1;
        person.oldFlag = 1;
        person.waitingTimes.push_back(currentTime - person.getPreTime());
        currentPeople++;
        ptimes++;
        addDestination(person.getDestination());
    }
    // 如果电梯不在乘客所在楼层或者电梯人数已满，
    // 则将乘客加入等待队列，并将乘客的等待标志置为1
    // 同时将乘客的所在楼层加入目标楼层队列
    else
    {
        // waitlist.push_back(person);
        PushPeople(waitlistArray, person);
        person.waitlistFlag = 1;
        person.oldFlag = 1;
        currentWaitlist++;
        addDestination(person.getCurrentFloor());
    }
}

// 删除乘客
void Elev::RemovePeople(Person &person)
{
    for (int i = 0; i < peopleArray.P.size(); i++)
    {
        if (peopleArray.P[i]->getId() == person.getId())
        {
            //TODO:注意这里可能有问题
            peopleArray.P.erase(peopleArray.P.begin() + i);
            currentPeople--;
        }
    }
}

// 获取当前载客量
int Elev::getPeople()
{
    return currentPeople;
}

// 获取当前等待乘客量
int Elev::getWaitlist()
{
    return currentWaitlist;
}

// 处理等待乘客
void Elev::ProcessWaitlist()
{
    int i = 0;
    // 遍历等待队列，如果电梯位于乘客所在楼层，并且电梯人数未满，则将乘客加入电梯
    while (i < waitlistArray.P.size() && waitlistArray.P.size()!=0 && currentPeople != maxPeople)
    {
        if (waitlistArray.P[i]->getCurrentFloor() == currentFloor)
        {
            // 将其waitlistFlag设置为0
            waitlistArray.P[i]->waitlistFlag = 0;
            // 将其isinFlag设置为1
            waitlistArray.P[i]->isinFlag = 1;
            // 将等待队列中的第一个乘客加入电梯
            waitlistArray.P[i]->waitingTimes.push_back(currentTime - waitlistArray.P[i]->getPreTime());
            peopleArray.P.push_back(waitlistArray.P[i]);
            addDestination(waitlistArray.P[i]->getDestination());
            currentPeople++;
            ptimes++;
            // 将等待队列中的第一个乘客删除
            waitlistArray.P.erase(waitlistArray.P.begin() + i);
            currentWaitlist--;
        }
        else
        {
            i++;
        }
    }
}

// 处理已经到达目标楼层的乘客
void Elev::ProcessArrivedPeople()
{
    int i;
    int finishedNum = 0; // 记录已经完成乘梯的乘客数量
    // 如果乘客到达目标楼层了并且如果乘客的calledtimes==maxtimes，则将乘客删除
    if (destinationFloor[currentFloor] == 1)
    {
        destinationFloor[currentFloor] = 0;
        i = 0;
        while(i<peopleArray.P.size())
        {
            if (peopleArray.P[i]->getDestination() == currentFloor)
            {
                // 如果乘客的目标楼层等于当前楼层，则将乘客删除
                // 将乘客的当前楼层设置为当前楼层
                peopleArray.P[i]->setCurrentFloor(currentFloor);
                // 并为乘客生成下一次请求
                peopleArray.P[i]->nextCall(currentTime);
                peopleArray.P[i]->oldFlag = 1;
                peopleArray.P[i]->isinFlag = 0;
                // 如果乘客到达的目标楼层为1楼
                // 且乘客的calledtimes==maxtimes，则将乘客总的计数-1
                if (currentFloor == 1 && peopleArray.P[i]->getCalledTimes() == peopleArray.P[i]->getCallTimes())
                {
                    peopleArray.P[i]->finishFlag = 1;
                }
                peopleArray.P.erase(peopleArray.P.begin() + i);
                currentPeople--;
            }
            else
            {
                i++;
            }
        }
        // 删除目标楼层队列中的该楼层
        destinations.remove(currentFloor);
    }
}

// 打印乘客状态
void Elev::printPeopleStatus()
{
    cout << "电梯内乘客：";
    for (int i = 0; i < peopleArray.P.size(); i++)
    {
        cout << "乘客 " << peopleArray.P[i]->getId() << " -> " << peopleArray.P[i]->getDestination() << " ";
    }
    cout << endl
         << endl;
}

// 运行电梯
void Elev::runElev()
{
    // 如果方向为上升
    if (currentDirection == 1)
    {
        UpFloor();
        runTime++;
    }
    // 如果方向为下降
    else if(currentDirection == -1)
    {
        DownFloor();
        runTime++;
    }
    // 如果为静止
    else
        freeTime++;
}

// 刷新时间
void Elev::refreshTime(int time)
{
    currentTime = time;
}

// 打印电梯运行与空闲时间
void Elev::PrintElevFinished()
{
    cout << id << "运行时间：" << runTime << "\t秒\t空闲时间：" << freeTime << "\t秒" << endl;
}

// 打印运输人次
void Elev::PrintElevPtimes()
{
    cout << id << "运输人次：" << ptimes << endl;
}