// 11. �Ʒ��� main()�� ����ȭ��ó�� �����ϵ��� Person Ŭ������ �����ϼ���.
#include <iostream>
#include <string>

using namespace std;

class Person {
    string name;
    int age;
public:
    Person() : Person("Anonymous", 0) {}
    Person(string n, int a) : name{n}, age{a} {
        cout << "������ ���� " << name << ", " << age << endl;
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
    cout << "�Ҹ��� ���� " << getName() << endl;
}

int main()
{
    Person baby;
    Person child("benny", 10);
    cout << "baby name = " << baby.getName() << endl;
    cout << "child name = " << child.getName() << endl;
}