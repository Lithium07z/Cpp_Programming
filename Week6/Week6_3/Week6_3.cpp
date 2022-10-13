#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Person
{
    unique_ptr<string> name;
    unique_ptr<int> age;

public:
    Person();
    Person(string n, int a);
    ~Person();
    void disPlay() const;
};

Person::~Person()
{
    cout << *name << " 객체 소멸" << endl;
}

Person::Person() : Person("null", 0) {}
Person::Person(string n, int a) : name{make_unique<string>(n)}, age{make_unique<int>(a)} {};
/*
Person::Person(string n, int a) {
name = make_unique<string>(n);
age = make_unique<int>(a);
}
*/
void Person::disPlay() const
{
    cout << "name = " << *name << ", age = " << *age << endl;
}

int main()
{
    unique_ptr<Person> p = make_unique<Person>("java", 30);
    p->disPlay();
    return 0;
}