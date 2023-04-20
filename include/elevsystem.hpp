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
};


#endif // !