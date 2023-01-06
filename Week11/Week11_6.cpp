#include <iostream>
#include <cstring>
#include <utility> //swap()

using namespace std;

class Person
{
    char *name;
    int id;

public:
    Person(int id, const char* name);
    Person(const Person &p);  
    ~Person() { delete[] name; };
    Person &operator=(const Person &&person); // 이동 대입 연산자
    void show() { cout << id << ',' << name << endl; };
    friend void swap_person(Person &first, Person &second);
};

Person::Person(int id, const char *name) {
    cout << "생성자 실행" << endl;
    this->id = id;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Person::Person(const Person &p) {
    cout << "복사 생성자 실행" << endl;
    this->id = p.id;
    this->name = new char[strlen(p.name) + 1];
    strcpy(this->name, p.name);
}

Person& Person::operator=(const Person &&person) {
    cout << "이동 대입 연산자 실행" << endl;
    Person temp(person);
    swap_person(*this, temp);
    return *this;
}

void swap_person(Person &first, Person &second) {
    swap(first.id, second.id);
    swap(first.name, second.name);
}

Person createObject()
{
    return Person(10, "Hallym"); // rvalue(값) 반환
}

int main()
{
    Person p1(1, "software");
    p1 = createObject(); //이동 대입 연산자 함수 호출
    p1.show();
    return 0;
}