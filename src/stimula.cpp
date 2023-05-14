#include <iostream>
#include <vector>
#include "stimula.hpp"
#include "person.hpp"
#include "elevsystem.hpp"
#include <ostream>
#include <fstream>
#include <string>

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
void startStimula(ElevSystem &ES, int &timeS)
{
    // string file_name;
    // file_name = "./log.txt";
    // ofstream outfile(file_name);

    cout << "----------------------------------------" << endl;
    cout << "\t开始仿真" << endl;
    int currenttime = 0;
    while (ES.getPeople() != ES.getFinishedNum())
    {
        // 打印乘客总量
        ES.printPeopleStatus(currenttime);

        // 打印电梯状态
        ES.printElevStatus();

        // 处理到达目标楼层的乘客
        ES.processArrivedPeople();

        // 处理waitlist中的乘客
        ES.processWaitlist();

        // 处理未进入电梯的乘客
        ES.processPeople();

        // 刷新每位乘客的楼层
        ES.refreshFloor();

        // 设置电梯新方向
        ES.setNewDirection();

        // 电梯运行1秒
        ES.runElev();
        currenttime++;

        ES.currentTime = currenttime;

        // 刷新电梯时间
        ES.refreshTime();

    }

    // 进行最后一次打印，即打印电梯运行结束后的状态
    // 打印乘客总量
    ES.printPeopleStatus(currenttime);
    // 先打印电梯状态
    ES.printElevStatus();

    cout << "------------------------------------------" << endl;
    cout << "-----------------仿真结束-----------------" << endl;
    cout << "------------------------------------------" << endl << endl;



    cout << "------------------------------------------" << endl;
    cout << "!!!!!!!!!!!!!!!!!仿真结果!!!!!!!!!!!!!!!!!" << endl;
    cout << "------------------------------------------" << endl << endl;

    cout << "------------------------------------------" << endl;
    cout << "---------------运行情况统计---------------" << endl;
    cout << "------------------------------------------" << endl << endl;

    // 输出电梯运行情况统计
    // 乘客人次
    ES.PrintElevPtimes();

    cout << "------------------------------------------" << endl;
    cout << "---------------乘客等待时间---------------" << endl;
    cout << "------------------------------------------" << endl << endl;

    // 打印乘客发出乘梯要求后的等待时间
    for(int i=0;i<ES.P.size();i++)
    {
        ES.P[i].PrintFinished();
    }

    cout << "------------------------------------------" << endl;
    cout << "---------------电梯两项时间---------------" << endl;
    cout << "------------------------------------------" << endl << endl;
    // 打印各电梯运行与空闲时间
    ES.PrintElevFinished();

}