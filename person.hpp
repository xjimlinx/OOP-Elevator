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

    public:
    // 基本方法
        // 方法对：id
        void setId(int id);
        int getId();
        // 方法对：destinationFloor
        void setDestinationFloor();
        int getDestinationFloor();
};

#endif
