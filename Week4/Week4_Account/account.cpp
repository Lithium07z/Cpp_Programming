#include "account.h"
#include <iostream>

using namespace std;
using namespace Bank;

void Account::deposit(int m)
{
    money += m;
}

string Account::getOwner()
{
    return name;
}

int Account::check()
{
    return money;
}

int Account::withdraw(int m)
{
    money -= m;
    return m;
}

Account::~Account() {
    cout << "2022 : 객체 소멸" << endl;
}
