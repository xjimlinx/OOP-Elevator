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