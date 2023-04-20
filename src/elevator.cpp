#include <iostream>
#include <vector>
#include "person.hpp"
#include "elevator.hpp"

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
    // 1为上 0为下
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

string Elev::getFloor()
{
    return to_string(currentFloor);
}

// 添加乘客
void Elev::AddPeople(Person &person)
{
    if (currentPeople < maxPeople)
    {
        people.push_back(person);
        currentPeople++;
    }
}

// 删除乘客
void Elev::RemovePeople(Person &person)
{
    for (int i = 0; i < currentPeople; i++)
    {
        // Todo:
    }
}

// 获取当前载客量
int Elev::getPeople()
{
    return currentPeople;
}