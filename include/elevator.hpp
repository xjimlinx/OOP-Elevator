#pragma once
#include <string>
#include <vector>
#include "person.hpp"
#include <algorithm>
#include <list>
#ifndef ELEVATOR_H
#define ELEVATOR_H

using namespace std;
class Elev
{
    private:
        // 基本属性：限制
        string id;                      // 电梯编号 从E0到E9
        int maxPeople = 15;             // 最大载客量
        vector<Person> people;          // 乘客
        vector<Person> waitlist;        // 等待乘客
        list <int> destinations;        // 目标楼层队列

        // 基本属性：状态
        int currentPeople = 0;          // 当前载客量 初始化为0
        int currentWaitlist = 0;        // 当前等待乘客量 初始化为0
        int currentFloor = 1;           // 当前楼层 初始化为1
        int currentDirection = 1;       // 当前运行方向 初始化为1 即向上
        int destinationFloor[40];       // 目标楼层 有40层，初始化为0
        int currentTime = 1;            // 每层用时 设无论有没有乘客，电梯都会以1秒一层的速度运行

    public:
        // 基本方法

        // 方法对：id
        void setID(string id);
        string getID();

        // 方法组：direction
        void setDirection(int direction);
        string getDirection();
        void setNewDirection();

        // 方法组：floor
        void UpFloor();                       // 上升楼层
        void DownFloor();                     // 下降楼层
        int getFloor();                       // 获取当前楼层
        void setDestinationFloor();           // 初始化目标楼层
        void addDestination(int destination); // 添加目标楼层

        // 方法组：people
        void AddPeople(Person &person);       // 添加乘客
        void RemovePeople(Person &person);    // 删除乘客
        int getPeople();                      // 获取当前载客量
        int getWaitlist();                    // 获取当前等待乘客量
        void ProcessWaitlist();               // 处理等待乘客
        void ProcessArrivedPeople();          // 处理到达目标楼层的乘客

        // 方法：运行电梯
        void runElev();
};

#endif