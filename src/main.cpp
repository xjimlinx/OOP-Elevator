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
    stimulaPrintVal(peopleNum, timeS);

    // 初始化电梯系统
    ElevSystem ES;

    ES.setElev();                       // 将10个电梯放入电梯系统中
    ES.printElevStatus();               // 打印电梯系统中电梯的状态（初始）

    vector<Person> P;                   // 乘客数组
    for (int i = 0; i < peopleNum; i++)
    {
        Person newPerson;
        newPerson.setId(i);
        newPerson.setDestinationFloor();
        P.push_back(newPerson);
    }

    // 打印乘客信息
    cout << "----------------------------------------" << endl;
    cout << "乘客信息: " << endl;
    for (int i = 0; i < peopleNum; i++)
    {
        cout << "乘客" << P[i].getId() << "目标楼层: " << P[i].getDestinationFloor() << endl;
    }

    return 0;

}