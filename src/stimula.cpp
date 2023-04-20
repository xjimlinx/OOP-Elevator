#include "stimula.hpp"
#include <iostream>
using namespace std;

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