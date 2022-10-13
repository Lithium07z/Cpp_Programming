#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Person
{
    string name;
    int age;

public:
    Person() = default;
    Person(string n, int t) : name(n), age(t){};
    ~Person() { cout << "객체 소멸" << endl; }
    void disPlay() { cout << "name = " << name << ", age = " << age << endl; }
};

int main()
{
    auto p = make_unique<Person>("unique", 20);
    p->disPlay();
}
