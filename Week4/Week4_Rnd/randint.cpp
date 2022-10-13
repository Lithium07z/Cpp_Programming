#include <iostream>
#include <random>
#include "randint.h"

void RandInt::print()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(low, high);
    int value = dis(gen);
    cout << "Random number between " << low << " and " << high << " : " << value << endl;
}

RandInt::~RandInt()
{
    cout << name << "객체 소멸" << endl;
}