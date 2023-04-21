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
        newElev.setDirection(1);
        newElev.setDestinationFloor();
        E.push_back(newElev);
    }
}

// 打印电梯系统中电梯的状态
void ElevSystem::printElevStatus()
{
    for (int i = 0; i < 10; i++)
    {
        cout << E[i].getID() << " " << E[i].getDirection() << " 位于" << E[i].getFloor() << "层" << " 有 " << E[i].getPeople() << "位乘客" << endl;
    }
}

// 将乘客加入电梯系统
void ElevSystem::joinPeople(Person &person)
{
    // 利用乘客的目标电梯的信息，将乘客加入电梯系统
    E[person.getElev()].AddPeople(person);
}

// 处理等待队列
void ElevSystem::processWaitlist()
{
    // 遍历电梯系统，如果电梯在第一层，且有乘客在等待，则将乘客加入电梯系统
    for(int i = 0; i < 10; i++)
    {
        if(E[i].getFloor() == 1)
        {
            // 处理等待的乘客
            E[i].ProcessWaitlist();
        }
    }
}

// 处理已经到达目标楼层的乘客
void ElevSystem::processArrivedPeople()
{
    // 遍历电梯系统，如果电梯到达目标楼层，则将乘客从电梯系统中移除
    for(int i = 0; i < 10; i++)
    {
        // 处理已经到达目标楼层的乘客
        E[i].ProcessArrivedPeople();
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