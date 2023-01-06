#include <iostream>
#include <string>
#include <cstring>
#include <utility> //swap()

using namespace std;

class Person
{
    char *name;
    int id;

public:
    Person(int id, const char *name);
    ~Person() { delete[] name; };
    Person(const Person &p);                           //복사생성자
    Person &operator=(const Person &rhs);              //대입(=) 연산자 함수
    Person &operator=(const Person &&person); //이동 대입(=) 연산자 함수
    void show() { cout << id << ',' << name << endl; }
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

Person& Person::operator=(const Person &rhs) {
    cout << "대입 연산자 실행" << endl;
    if (this == &rhs) //자기 자신을 대입
        return *this;
    Person temp(rhs);      //임시 객체 생성
    swap_person(*this, temp); //현재 객체를 생성된 임시 복사본으로 교체
    return *this;
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
    Person father(1, "Kitae");
    Person daughter(2, "Grace");

    father.show();
    daughter.show();

    father = daughter; //대입 연산자 함수 호출

    father.show();
    daughter.show();

    Person p1(1, "software");

    p1.show();
    p1 = createObject(); //이동 대입 연산자 함수 호출
    p1.show();

    return 0;
}
