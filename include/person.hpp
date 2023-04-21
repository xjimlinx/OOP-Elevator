#pragma once
#include <vector>
#ifndef PERSON_H
#define PERSON_H

class Person
{
    private:
    // 基本属性
        int id;               // 乘客编号
        int destinationFloor; // 目标楼层
        int elevNum;          // 电梯编号
        int joinTime;         // 乘客加入时间

    public:
    // 基本方法

        // 方法对：id
        void setId(int id);
        int getId();

        // 方法组：destinationFloor
        void setDestination();
        int getDestination();
        void printDestination();

        // 方法组：电梯
        void setElev();
        int getElev();

        // 方法组：乘客加入时间，单位为秒
        void setJoinTime(int timeS);
        int getJoinTime();
        void printJoinTime();

        void printPersonInfo();
};

#endif
