#pragma once

#include <vector>

#include "elevator.hpp"

#ifndef ELEVSYSTEM_H
#define ELEVSYSTEM_H

class ElevSystem
{
    private:
        vector<Elev> E;
    public:
        void setElev();                 // 初始化电梯
        void printElevStatus();         // 打印电梯状态
        void joinPeople(Person &person);// 乘客加入电梯
        void processWaitlist();         // 处理等待队列
        void processArrivedPeople();    // 开门卸货！ （处理到达目标楼层的乘客）
        void setNewDirection();         // 设置电梯的新方向
        void runElev();                 // 电梯运行
};


#endif // !