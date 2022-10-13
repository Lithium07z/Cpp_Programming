#pragma once
#include <string>

using namespace std;

class RandInt {
    int low;
    int high;
    string name;
public:
    RandInt(int l, int h, string n) : low(l), high(h), name(n) {};
    void print();
    ~RandInt();
};