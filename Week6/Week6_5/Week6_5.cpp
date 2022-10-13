#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Person
{
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a){};
    ~Person() { cout << "메모리 해제" << endl; };
    void disPlay() { cout << "name = " << name << ", age = " << age << endl; }
    std::shared_ptr<Person> per; //해결방법 weak_ptr
};

void show(shared_ptr<Person> sp)
{
    sp->disPlay();
    cout << "show().sp.use_count() : " << sp.use_count() << endl;
}

int main()
{
    auto sp1 = make_shared<Person>("unique", 17);
    show(sp1);
    cout << "sp1.use_count() : " << sp1.use_count() << endl;
    sp1->per = sp1;
    show(sp1->per);
    cout << "sp1.use_count() : " << sp1.use_count() << endl;
}
