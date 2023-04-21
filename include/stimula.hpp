#pragma once
#include <vector>
#include <iostream>
#include "person.hpp"
#include "elevsystem.hpp"
#include <ostream>

using namespace std;

#ifndef STIMULA_HPP
#define STIMULA_HPP

void stimulaSetVal(int &peopleNumber, int &timeS);
void stimulaPrintVal(int peopleNumber, int timeS);
void startStimula(vector<Person> P, ElevSystem &ES, int &timeS);

#endif // !