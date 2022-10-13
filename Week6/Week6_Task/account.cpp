#include "account.h"
#include <string>

using namespace std;
using namespace Bank;

void Account::deposit(int money) {
    this->money += money;
}

string Account::getOwner() {
    return this->owner;
}

int Account::check() {
    return this->money;
}

int Account::withdraw(int money) {
    this->money -= money;
    return money;
}