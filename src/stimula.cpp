#include "stimula.hpp"
#include <iostream>
using namespace std;

// 设置目标乘客数量与电梯运行时间
void stimulaSetVal(int &peopleNum, int &timeS)
{
    while(1)
    {
        cout << "请输入要仿真的人数（1到1000）: " << endl;
        cin >> peopleNum;
        if (peopleNum >= 1 && peopleNum <= 1000)
        {
            break;
        }
        else
        {
            cout << "输入错误，请重新输入" << endl;
        }
    }
    while(1)
    {
        cout << "请输入要仿真的电梯运行时间（1到10）: " << endl;
        cin >> timeS;
        if (timeS >= 1 && timeS <= 10)
        {
            break;
        }
        else
        {
            cout << "输入错误，请重新输入" << endl;
        }
    }
}

// 打印目标乘客数量与目标运行时间信息
void stimulaPrintVal(int peopleNum, int timeS)
{
    cout << "----------------------------------------" << endl;
    cout << "\t初始化目标乘客数量: " << peopleNum << endl;
    cout << "\t初始化目标电梯运行时间: " << timeS << endl;
    cout << "----------------------------------------" << endl;
}