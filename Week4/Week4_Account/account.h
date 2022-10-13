#include <string>
#pragma once

using namespace std;

namespace Bank
{
    enum class MENU
    {
        DEPOSIT = 1,
        WITHDRAW = 2,
        CHECK = 3
    };

    class Account {
    public:
        string name;
        int money;

        Account(string n, int m) : name(n), money(m) {};

        void deposit(int money);
        string getOwner();
        int check();
        int withdraw(int money);

        ~Account();
    };
}