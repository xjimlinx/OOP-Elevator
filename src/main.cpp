#include <iostream>
#include "elevator.hpp"
#include "person.hpp"
#include "elevsystem.hpp"
#include <vector>

using namespace std;

int main()
{
    int peopleNum;                      // 乘客数量 从1到999
    cout << "peopleNum: " << endl;
    cin >> peopleNum;

    int timeS;                          // 电梯运行时间 从1到9分钟
    cout << "timeS: " << endl;
    cin >> timeS;

    ElevSystem ES;

    ES.setElev();
    ES.printElevStatus();

    return 0;

}