#include <iostream>

#include "elevsystem.hpp"
#include "elevator.hpp"

using namespace std;

void ElevSystem::setElev()
{
    for (int i = 0; i < 10; i++)
    {
        Elev newElev;
        newElev.setID("E" + to_string(i));
        newElev.setDirection(1);
        E.push_back(newElev);
    }
}

void ElevSystem::printElevStatus()
{
    for (int i = 0; i < 10; i++)
    {
        cout << E[i].getID() << " " << E[i].getDirection() << " 位于" << E[i].getFloor() << "层" << " 有 " << E[i].getPeople() << "位乘客" << endl;
    }
}