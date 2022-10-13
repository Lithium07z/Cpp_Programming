#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

namespace Bank{
    enum class MENU {DEPOSIT = 1, WITHDRAW = 2, CHECK = 3, QUIT = 4};

    class Account {
        string owner;
        int money;
        public:
            Account(string owner, int money) : owner{owner}, money{money} {};
            void deposit(int money);
            string getOwner();
            int check();
            int withdraw(int money);
            ~Account() {cout << "C++: 객체 소멸" << endl;};
    };
}

#endif