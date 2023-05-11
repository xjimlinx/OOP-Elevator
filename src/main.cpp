#include <iostream>
#include "elevator.hpp"
#include "person.hpp"
#include "elevsystem.hpp"
#include "stimula.hpp"
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int peopleNum;                      // 乘客数量 从1到999
    int timeS;                          //  从1到9分钟

    // 设置乘客数量、乘客加入的时间
    stimulaSetVal(peopleNum, timeS);

    stimulaPrintVal(peopleNum, timeS);

    // 初始化电梯系统
    ElevSystem ES;

    ES.setElev();                       // 将10个电梯放入电梯系统中
    ES.setPeople(peopleNum);                     // 初始化电梯系统中的乘客数量
    ES.printElevStatus();               // 打印电梯系统中电梯的状态（初始）

    // 初始化乘客、乘客目标楼层、乘客到达的时间（秒）
    vector<Person> P;                   // 乘客数组

    cout << "-------------------------------------------------" << endl;
    for (int i = 0; i < peopleNum; i++)
    {
        Person newPerson;
        newPerson.setId(i+1);               // 设置乘客id
        newPerson.setDestination();         // 设置乘客目标楼层
        newPerson.setJoinTime(timeS);       // 设置乘客加入时间
        newPerson.chooseElev();                // 选择电梯
        newPerson.setCallTimes();           // 设置乘客呼叫电梯次数
        P.push_back(newPerson);             // 将乘客放入乘客数组中
        newPerson.printPersonInfo();        // 打印乘客目标楼层
    }
    cout << "-------------------------------------------------" << endl;
    // 将乘客加入到电梯系统中
    ES.setPeopleContainer(P);

    // 模拟时间，每一秒更新一次，直到所有乘客到达目标楼层
    startStimula(ES, timeS);

    return 0;
}