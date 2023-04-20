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
    while(1)
    {
        cout << "请输入要仿真的人数（1到999）: " << endl;
        cin >> peopleNum;
        if (peopleNum >= 1 && peopleNum <= 999)
        {
            break;
        }
        else
        {
            cout << "输入错误，请重新输入" << endl;
        }
    }

    int timeS;                          // 电梯运行时间 从1到9分钟
    while(1)
    {
        cout << "请输入要仿真的电梯运行时间（1到9）: " << endl;
        cin >> timeS;
        if (timeS >= 1 && timeS <= 9)
        {
            break;
        }
        else
        {
            cout << "输入错误，请重新输入" << endl;
        }
    }
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