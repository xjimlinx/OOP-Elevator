#include "person.hpp"
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

// 初始化id
void Person::setId(int id)
{
    this->id = id;
}

// 访问id
int Person::getId()
{
    return id;
}

// 设置目标楼层
void Person::setDestination()
{
    destinationFloor = rand() % 40 + 1;
    // 目标楼层不为1
    if (destinationFloor == 1)
    {
        destinationFloor = 2;
    }
}

// 访问目标楼层
int Person::getDestination()
{
    return destinationFloor;
}

// 打印目标楼层
void Person::printDestination()
{
    cout << "乘客" << id << "目标楼层: " << destinationFloor << endl;
}

// 选择电梯
void Person::setElev()
{
    elevNum = rand() % 10;
}

// 获取电梯
int Person::getElev()
{
    return elevNum;
}

// 设置乘客加入时间
void Person::setJoinTime(int timeS)
{
    joinTime = rand() % (timeS * 60) + 1;
}

// 获取乘客加入时间
int Person::getJoinTime()
{
    return joinTime;
}

// 打印乘客加入时间
void Person::printJoinTime()
{
    cout << "乘客" << id << "加入时间: " << joinTime << endl;
}

// 打印乘客信息
void Person::printPersonInfo()
{
    if(id!=1000)
        cout << "乘客" << id << "\t\t目标楼层: " << destinationFloor << "\t\t加入时间: " << joinTime <<  "\t\t选择电梯: E[" << elevNum << "]" << endl;
    else
        cout << "乘客" << id << "\t目标楼层: " << destinationFloor << "\t\t加入时间: " << joinTime <<  "\t\t选择电梯: E[" << elevNum << "]" << endl;
}

// 设置乘客请求次数
void Person::setCallTimes()
{
    // 产生次数在1～10之间的随机数
    maxcalltimes = rand() % 10 + 1;
    calledtimes = 0;
}

// 获取乘客请求次数
int Person::getCallTimes()
{
    return maxcalltimes;
}

// 获取乘客已经请求的次数
int Person::getCalledTimes()
{
    return calledtimes;
}

// 增加乘客已经请求的次数
void Person::addCalledTimes()
{
    calledtimes++;
}

// 设置两次次数间隔时间
void Person::setWaitingTime()
{
    // 随即停留时间10～120秒
    waitingTime = rand() % 111 + 10;
}

// 获取两次次数间隔时间
int Person::getWaitingTime()
{
    return waitingTime;
}

// 减少两次次数间隔时间
void Person::delWaitingTime()
{
    if(waitingTime == 0)
        return;
    else
        waitingTime--;
}

// 重新生成下一次要进行的请求
void Person::nextCall()
{
    if(calledtimes < maxcalltimes)
    {
        // 如果还有请求次数，重新生成下一次要进行的请求
        setDestination();
        setElev();
        addCalledTimes();
        setWaitingTime();
    }
    else
    {
        // 如果没有请求次数，将目标楼层设置为1
        destinationFloor = 1;
        setWaitingTime();
    }
}

// 设置乘客的当前楼层
void Person::setCurrentFloor(int floor)
{
    currentFloor = floor;
}

// 获取乘客的当前楼层
int Person::getCurrentFloor()
{
    return currentFloor;
}

// 刷新乘客的当前楼层
void Person::refreshFloor(int floor)
{
    currentFloor = floor;
}