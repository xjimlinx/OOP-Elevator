#pragma once

#include <vector>

#include "elevator.hpp"
#include "person.hpp"

#ifndef ELEVSYSTEM_H
#define ELEVSYSTEM_H

class ElevSystem
{
    private:
        vector<Elev> E;                 // 电梯
        int peopleNum;                  // 乘客总数
        int finishedNum = 0;                // 已完成乘客数
    public:
        vector<Person> P;               // 乘客
        int currentTime = 0;            // 当前时间
        void setElev();                 // 初始化电梯
        void printElevStatus();         // 打印电梯状态
        void joinPeople(Person &person);// 乘客加入电梯
        void processNewPeople();        // 处理新乘客
        void processWaitlist();         // 处理等待队列
        void processPeople();           // 处理未进入电梯的乘客
        void processArrivedPeople();    // 开门卸货！ （处理到达目标楼层的乘客）
        void refreshFloor();            // 刷新电梯的楼层
        void setNewDirection();         // 设置电梯的新方向
        void runElev();                 // 电梯运行

        void setPeople(int peopleNum);               // 初始化乘客总数
        void setPeopleContainer(vector<Person> &P);  // 初始化乘客容器
        int getPeople();                             // 获取乘客总数
        void printPeopleStatus(int currenttime);     // 打印乘客状态
        int getFinishedNum();                       // 获取已完成乘客数
};

#endif // !