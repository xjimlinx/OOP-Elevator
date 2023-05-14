#include <iostream>

#include "elevsystem.hpp"
#include "elevator.hpp"

using namespace std;


// 初始化电梯系统，加入10个电梯
void ElevSystem::setElev()
{
    for (int i = 0; i < 10; i++)
    {
        Elev newElev;
        newElev.setID("E" + to_string(i));
        newElev.setDirection(0);
        newElev.setDestinationFloor();
        E.push_back(newElev);
    }
}

// 打印电梯系统中电梯的状态
void ElevSystem::printElevStatus()
{
    for (int i = 0; i < 10; i++)
    {
        cout << E[i].getID() << "\t" << E[i].getDirection() << "\t位于" << E[i].getFloor() << "层" << "\t有\t" << E[i].getPeople() << "\t位乘客-----" << E[i].getWaitlist() << "\t位正在等待" << endl;
        E[i].printPeopleStatus();
    }
}

// 将乘客加入电梯系统
void ElevSystem::joinPeople(Person &person)
{
    // 利用乘客的目标电梯的信息，将乘客加入电梯系统
    E[person.getElev()].AddPeople(person);
}

// 处理新乘客
void ElevSystem::processNewPeople()
{
    for (int i = 0; i < P.size(); i++)
    {
        // 添加第一次乘坐电梯的乘客
        if (P[i].getJoinTime() == currentTime && P[i].getCalledTimes() == 0)
        {
            joinPeople(P[i]);
        }
    }
}

// 处理等待队列
void ElevSystem::processWaitlist()
{
    // 遍历电梯系统，如果有乘客在等待，则将乘客加入电梯系统
    for(int i = 0; i < 10; i++)
    {
        // 处理等待的乘客
        E[i].ProcessWaitlist();
    }
}

// 处理未进入电梯的乘客
void ElevSystem::processPeople()
{
    for(int i=0; i < P.size(); i++)
    {
        // 如果是老乘客，且未完成，且不在电梯中
        if(P[i].oldFlag == 1 && P[i].finishFlag == 0 && P[i].isinFlag == 0)
        {
            // 如果不在waitlist中
            if(P[i].waitlistFlag == 0)
            {
                // 如果waitingtime为0，则将乘客加入电梯或者电梯的waitlist
                if (P[i].getWaitingTime() == 0)
                {
                    joinPeople(P[i]);
                }
                // 对waitingtime进行减1操作
                P[i].delWaitingTime();
            }
        }
        // 如果是新乘客
        else if(P[i].oldFlag == 0)
        {
            if (P[i].getJoinTime() == currentTime && P[i].getCalledTimes() == 0)
            {
                joinPeople(P[i]);
            }
        }
        //  已经完成的乘客
        else
        {
            ;
        }

    }
}

// 处理已经到达目标楼层的乘客
void ElevSystem::processArrivedPeople()
{
    // 遍历电梯系统，如果电梯到达目标楼层，则将乘客从电梯系统中移除
    for(int i = 0; i < 10; i++)
    {
        // OLD:
        // 处理已经到达目标楼层的乘客
        // peopleNum -= E[i].ProcessArrivedPeople();

        // NEW:
        // 判断终止的条件已经改变，所以这里需要改变
        E[i].ProcessArrivedPeople();
    }
}

void ElevSystem::refreshFloor()
{
    // 遍历电梯系统,刷新每个乘客的当前楼层
    for(int i = 0; i < 10; i++)
    {
        // 处理电梯的楼层
        E[i].refreshFloor();
    }
}

// 处理电梯的运行的新方向
void ElevSystem::setNewDirection()
{
    // 遍历电梯系统，如果电梯到达目标楼层，则将电梯的运行方向改变
    for(int i = 0; i < 10; i++)
    {
        // 处理电梯的运行方向
        E[i].setNewDirection();
    }
}

// 电梯运行
void ElevSystem::runElev()
{
    for(int i = 0; i < 10; i++)
    {
        // 处理电梯的运行方向
        E[i].runElev();
    }
}

// 刷新电梯时间
void ElevSystem::refreshTime()
{
    for(int i = 0; i < 10; i++)
    {
        E[i].refreshTime(currentTime);
    }
}

// 初始化乘客总数
void ElevSystem::setPeople(int peopleNum)
{
    this->peopleNum = peopleNum;
}

void ElevSystem::setPeopleContainer(vector<Person> &peopleContainer)
{
    this->P = peopleContainer;
}


// 获取乘客总数
int ElevSystem::getPeople()
{
    return this->peopleNum;
}

// 打印乘客状态
void ElevSystem::printPeopleStatus(int currenttime)
{
    cout << "----------当前时间：" << currenttime << "秒----------乘客总数：" << peopleNum << "----------" <<  "已完成乘客数：" << finishedNum << "----------"<< endl ;
}

int ElevSystem::getFinishedNum()
{
    finishedNum = 0;
    // 遍历电梯系统，如果乘客的finishFlag为1，则计数器加一
    for(int i=0;i<P.size();i++)
    {
        if(P[i].finishFlag == 1)
        {
            finishedNum++;
        }
    }
    return finishedNum;
}


// 打印电梯运行与空闲时间
void ElevSystem::PrintElevFinished()
{
    for (int i = 0; i < 10; i++)
    {
        E[i].PrintElevFinished();
    }
}

// 打印电梯运输人次
void ElevSystem::PrintElevPtimes()
{
    int sumPtimes = 0;
    for (int i = 0; i < 10; i++)
    {
        E[i].PrintElevPtimes();
        sumPtimes += E[i].ptimes;
    }
    cout << endl;

    cout << "电梯运行总人次" << sumPtimes << endl;

    cout << endl;
}