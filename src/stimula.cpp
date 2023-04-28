#include <iostream>
#include <vector>
#include "stimula.hpp"
#include "person.hpp"
#include "elevsystem.hpp"
#include <ostream>

using namespace std;

// 设置目标乘客数量与游客加入的时间
void stimulaSetVal(int &peopleNum, int &timeS)
{
    while (1)
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
    while (1)
    {
        cout << "请输入要仿真的游客到达的时间范围（1到10）: " << endl;
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
    cout << "-------------------------------------------------" << endl;
    cout << "\t初始化乘客数量: " << peopleNum << endl;
    cout << "\t初始化乘客加入时间: " << timeS << endl;
    cout << "-------------------------------------------------" << endl;
}

// 开始仿真
void startStimula(vector<Person> P, ElevSystem &ES, int &timeS)
{
    cout << "----------------------------------------" << endl;
    cout << "\t开始仿真" << endl;
    int currenttime = 0;
    while (ES.getPeople() != 0)
    {
        // 打印乘客总量
        ES.printPeopleStatus(currenttime);
        // 先打印电梯状态
        ES.printElevStatus();

        // 处理waitlist中的乘客
        ES.processWaitlist();

        // 再处理新加入的乘客
        for (int i = 0; i < P.size(); i++)
        {
            if (P[i].getJoinTime() == currenttime)
            {
                ES.joinPeople(P[i]);
            }
        }

        // 处理到达目标楼层的乘客
        ES.processArrivedPeople();

        // 设置电梯新方向
        ES.setNewDirection();

        // 电梯运行1秒
        ES.runElev();
        currenttime++;
    }

    // 进行最后一次打印，即打印电梯运行结束后的状态
    // 打印乘客总量
    ES.printPeopleStatus(currenttime);
    // 先打印电梯状态
    ES.printElevStatus();

    cout << "----------------------------------------" << endl;
    cout << "-----------------仿真结束-----------------" << endl;
}