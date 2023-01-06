#include <iostream>
#include <cstring>

using namespace std;

class Person
{
    char *name;
    int id;

public:
    Person(int id, const char* name) : id{id}, name{new char[strlen(name) + 1]} { strcpy(this->name, name); cout << "생성자 실행" << endl; };
    Person &operator=(const Person &person);
    Person(const Person& p);
    ~Person() { delete [] name; }; 
    void show() { cout << id << ',' << name << endl; };
    void changeName(const char* name);
    //표준 라이브러리 알고리즘에서 활용할 수 있게 외부 함수로 swap_person() 추가
    //단, 복사 과정에서 예외가 발생하지 않도록 한다.
    friend void swap_person(Person &first, Person &second) noexcept;
};

Person::Person(const Person& p) {
    cout << "복사 생성자 실행" << endl;
    this->id = p.id;
    this->name = new char[strlen(p.name) + 1];
    strcpy(this->name, p.name);
}

Person &Person::operator=(const Person &person)
{
    cout << "대입 연산자 실행" << endl;
    if (this == &person) //자기 자신을 대입
        return *this;
    Person temp(person);      //임시 객체 생성
    swap_person(*this, temp); //현재 객체를 생성된 임시 복사본으로 교체
    return *this;
}

void swap_person(Person &first, Person &second) noexcept
{
    //표준 라이브러리(<utility>) 에서 제공하는 유틸리티 swap() 함수를 사용 간단히 처리
    //추후 Person 클래스 멤버 변수 추가 시 swap_person() 함수만 수정하면 됨
    swap(first.id, second.id);
    swap(first.name, second.name);
}

void Person::changeName(const char* name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

int main()
{
    Person father(1, "Kitae");
    Person daughter(father);
    daughter.changeName("Grace");
    father = daughter; //대입 연산자 함수 호출
    father.show();
    daughter.show();
    return 0;
}
