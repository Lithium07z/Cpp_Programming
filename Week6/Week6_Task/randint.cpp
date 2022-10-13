#include "randint.h"
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

RandInt::RandInt(int low, int high, string cn) {
    this->low = low; this->high = high; this->objname = cn;
}

void RandInt::print() const {
    mt19937 gen(time(nullptr)); //mt19937 gen(clock()); //시간을 이용해 난수 생성 엔진 초기화
    uniform_int_distribution<int> int_rd(low, high); 
    cout << "Random number between " << low << " and " << high << " : " << int_rd(gen) << endl;
}  

RandInt::~RandInt() {
    cout << objname << "객체 소멸" << endl;
}