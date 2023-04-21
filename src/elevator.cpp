#include <iostream>
#include <vector>
#include "person.hpp"
#include "elevator.hpp"
using namespace std;

// 初始化id
void Elev::setID(string id)
{
    this->id = id;  // 这里用this->id是为了区分局部变量id和成员变量id
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
    else
    {
        return "下降";
    }
}

// 设置新的方向
void Elev::setNewDirection()
{
    // 如果目标楼层队列为空，则方向向下，回到第一层
    if (destinations.empty())
    {
        currentDirection = -1;
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
    for (int i = 0; i < 40; i++)
    {
        destinationFloor[i] = 0;
    }
}

// 添加目标楼层
void Elev::addDestination(int destination)
{
    // 目标楼层队列中有该楼层，不做任何操作
    if(destinationFloor[destination] == 1)
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

    // 注意：在每一次刷新时，先将等待队列中的乘客加入电梯，再将新乘客加入电梯
    // 如果电梯不在第一层或者电梯人数已满，则将乘客加入等待队列
    if (currentFloor != 1 || currentPeople == maxPeople)
    {
        waitlist.push_back(person);
        currentWaitlist++;
        return;
    }
    // 如果电梯在第一层且电梯人数未满，则将乘客加入电梯
    else
    {
        people.push_back(person);
        currentPeople++;
        addDestination(person.getDestination());
    }
}

// 删除乘客
void Elev::RemovePeople(Person &person)
{
    for (int i = 0; i < people.size(); i++)
    {
        if (people[i].getId() == person.getId())
        {
            people.erase(people.begin() + i);
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
    while(1)
    {
        if(waitlist.size() == 0)
        {
            // 等待队列为空
            break;
        }
        else if(currentPeople == maxPeople)
        {
            // 电梯人数已满
            break;
        }
        else
        {
            // 将等待队列中的第一个乘客加入电梯
            people.push_back(waitlist[0]);
            addDestination(waitlist[0].getDestination());
            currentPeople++;
            // 将等待队列中的第一个乘客删除
            waitlist.erase(waitlist.begin());
            currentWaitlist--;
            // erase 是删除指定位置的元素，erase(begin()+i)是删除第i个元素
            // 并且erase是释放内存的，所以erase后，后面的元素会向前移动
            // 而在之前，已经将第一个元素加入电梯，两个元素是独立的，所以不会出现问题
        }
    }
}

// 处理已经到达目标楼层的乘客
void Elev::ProcessArrivedPeople()
{
    // 如果当前楼层为目标楼层之一，则将乘客删除
    if (destinationFloor[currentFloor] == 1)
    {
        destinationFloor[currentFloor] = 0;
        for (int i = 0; i < people.size(); i++)
        {
            if (people[i].getDestination() == currentFloor)
            {
                // 如果乘客的目标楼层等于当前楼层，则将乘客删除
                people.erase(people.begin() + i);
                currentPeople--;
            }
        }
        // 删除目标楼层队列中的该楼层
        destinations.remove(currentFloor);
    }
}

// 运行电梯
void Elev::runElev()
{
    // 如果方向为上升
    if (currentDirection == 1)
    {
        UpFloor();
    }
    // 如果方向为下降
    else
    {
        DownFloor();
    }
}