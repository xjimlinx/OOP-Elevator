#pragma once
#include <vector>
#ifndef PERSON_H
#define PERSON_H

class Person
{
    friend class ElevSystem;
    friend class Elev;

    private:
    // 基本属性
        int id;               // 乘客编号
        int destinationFloor; // 目标楼层
        int elevNum;          // 电梯编号
        int joinTime;         // 乘客加入时间
        int maxcalltimes;     // 乘客请求次数
        int calledtimes;      // 乘客已经请求的次数
        int waitingTime;      // 乘客等待时间
        int nextjoinTime = 0;     // 下一次加入时间
        int currentFloor = 1;     // 当前楼层


    public:
    // 基本属性
        int isinFlag = 0;     // 是否在电梯中
        int waitlistFlag = 0; // 是否在等待队列中
        int oldFlag = 0;      // 是否是第一次请求
        int finishFlag = 0;   // 是否完成请求
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

        // 方法组：乘客请求次数
        void setCallTimes();
        int getCallTimes();
        int getCalledTimes();
        void addCalledTimes();

        // 方法组：乘客等待时间
        void setWaitingTime();
        int getWaitingTime();
        void delWaitingTime();

        // 方法：重新生成下一次要进行的请求
        void nextCall();
        void setCurrentFloor(int floor);
        int getCurrentFloor();
        void refreshFloor(int floor);

        // 方法：第三次添加、选择电梯
        void chooseElev();
};

#endif
