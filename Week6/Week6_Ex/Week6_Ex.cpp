// 11. 아래의 main()이 실행화면처럼 동작하도록 Person 클래스를 선언하세요.
#include <iostream>
#include <string>

using namespace std;

class Person {
    string name;
    int age;
public:
    Person() : Person("Anonymous", 0) {}
    Person(string n, int a) : name{n}, age{a} {
        cout << "생성자 수행 " << name << ", " << age << endl;
    }
    string getName();
    int getAge();
    ~Person();
};

string Person::getName() {
    return name;
}

int Person::getAge() {
    return age;
}

Person::~Person() {
    cout << "소멸자 수행 " << getName() << endl;
}

int main()
{
    Person baby;
    Person child("benny", 10);
    cout << "baby name = " << baby.getName() << endl;
    cout << "child name = " << child.getName() << endl;
}