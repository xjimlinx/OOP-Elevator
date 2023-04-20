#include "person.hpp"
#include <cstdlib>
#include <vector>

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
void Person::setDestinationFloor()
{
    destinationFloor = rand() % 40 + 1;
}

// 访问目标楼层
int Person::getDestinationFloor()
{
    return destinationFloor;
}
