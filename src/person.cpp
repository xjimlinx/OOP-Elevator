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
    // 目标楼层不为1 或者等于当前楼层
    while(destinationFloor == 1 || destinationFloor == currentFloor)
    {
        destinationFloor = rand() % 40 + 1;
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
    // 第一个“上次时间”是加入时间
    preTime = joinTime;
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

// 获取上一次发出请求时间
int Person::getPreTime()
{
    return preTime;
}

// 重新生成下一次要进行的请求
void Person::nextCall(int currentTime)
{
    if(calledtimes < maxcalltimes)
    {
        // 如果还有请求次数，重新生成下一次要进行的请求
        setDestination();
        chooseElev();
        addCalledTimes();
        setWaitingTime();
    }
    else
    {
        // 如果没有请求次数，将目标楼层设置为1
        destinationFloor = 1;
        chooseElev();
        setWaitingTime();
    }
    preTime = currentTime + waitingTime;
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

// 根据乘客信息选择电梯
void Person::chooseElev()
{
    // 可以坐E2、E3的情况 1、25～40层
    if((getCurrentFloor()==1||getCurrentFloor()>=25)&&(getDestination()>=25||getDestination()==1))
    {
        elevNum = rand() % 2 + 2;
    }
    // 可以坐E4、E5的情况 1~25层
    else if((getCurrentFloor()<=25&&getDestination()<=25))
    {
        elevNum = rand() % 2 + 4;
    }
    // 可以坐E6、E7的情况 偶数层
    else if((getCurrentFloor()==1&&getDestination()%2==0) || getCurrentFloor()%2==0&&(getDestination()==1||getDestination()%2==0))
    {
        elevNum = rand() % 2 + 6;
    }
    // 可以坐E8、E9的情况 奇数层
    else if(getCurrentFloor()%2!=0 && getDestination() %2 != 0)
    {
        elevNum = rand() % 2 + 8;
    }
    // 只可以坐E0、E1的情况
    else
    {
        elevNum = rand() % 2;
    }
}

void Person::PrintFinished()
{

    // 打印乘客发出乘梯要求后的等待时间
    // 如何计算？
    // 用加入电梯的时间减去上一次发出要求的时间
    // 统计在Elev类中执行
    for(int i=0;i<waitingTimes.size();i++)
    {
        cout << "乘客" << id << "\t第" << i+1 << "次: " << "等待\t" << waitingTimes[i] << "秒"<< endl;
    }
}