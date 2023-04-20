#include <iostream>
#include "elevator.hpp"
#include "person.hpp"
#include "elevsystem.hpp"
#include "stimula.hpp"
#include <vector>

using namespace std;

int main()
{
    int peopleNum;                      // 乘客数量 从1到999
    int timeS;                          // 电梯运行时间 从1到9分钟

    // 设置乘客数量与电梯运行时间
    stimulaSetVal(peopleNum, timeS);


    // 打印乘客与时间信息
    cout << "----------------------------------------" << endl;
    cout << "乘客数量: " << peopleNum << endl;
    cout << "电梯运行时间: " << timeS << endl;
    cout << "----------------------------------------" << endl;

    ElevSystem ES;

    ES.setElev();
    ES.printElevStatus();

    return 0;

}