// 2. 복사 생성자가 자동으로 호출되는 경우는 어떤 경우인지 설명하고 그 예를 보이세요.
// 1) 객체로 초기화하여 객체가 생성될 때
// Ex. Person son = father;
// 2) '값에 의한 호출'로 객체가 전달될 때
// Ex. void f(Person per);
//     main () {
//         Person p;
//         f(p);
//     }
// 3) 객체를 리턴할 때 컴파일러마다 다름, 복사 생성자 또는 복사 대입 연산자(=) 둘 중 하나가 호출
// Ex. Person g() {
//         Person p;
//         return p;
// }       
//     main() {
//         Person rst = g();
// }

// 3. Sample 객체 a에 대한 참조변수 ref를 선언하는 문장을 제시하세요.
// Sample a;
// Sample &ref = a;

// 4. Sample 클래스의 복사 생성자를 선언하는 함수원형을 제시하세요. 단, 매개변수는 s로 합니다.
// Sample(const Sample &s);

// 5. Person 클래스의 선언이 다음과 같은 경우 Person 클래스의 복사 생성자를 선언하는 문장을 제시하세요.

class Person
{ // Person 클래스 선언
    char *name;
    int id;

public:
    Person(const Person &p); //복사 생성자
};

Person::Person(const Person &p)
{
    int len = strlen(p.name);
    this->name = new char[len + 1];
    strcpy(this->name, p.name);

    this->id = p.id;
}

// 6. Person 클래스의 선언이 다음과 같은 경우 Person 클래스의 이동 생성자를 선언하는 문장을 제시하세요.

class Person
{ // Person 클래스 선언
    char *name;
    int id;

public:
    Person(Person &&p); //이동 생성자
};

Person::Person(Person &&p)
{
    this->id = p.id;
    this->name = p.name;
    p.id = 0;
    p.name = nullptr;
}

// 7. Accumulator 클래스는 생성자 매개변수로 전달된 값을 누적 저장하는 기능을 합니다. 아래에 제시된 클래스 선언과 main() 함수 그리고 실행결과를 참고하여 add() 함수를 작성하세요.

#include <iostream>

using namespace std;

class Accumulator
{
    int value;

public:
    Accumulator(int val) : value{val} {};
    Accumulator &add(int n);
    int get() { return value; }
};

Accumulator& Accumulator::add(int n) {
    this->value += n;
    return *this;
}

int main()
{
    Accumulator acc(10);
    cout << acc.get() << endl; // 10 출력
    acc.add(1).add(2).add(3);  // acc 객체의 value는 16이 됨. 
    cout << acc.get() << endl; //16 출력
}

// 8. Account 클래스는 생성자 매개변수로 전달된 값을 멤버변수에 balance(잔액)에 저장합니다. 이 후 
// increaseBy() 함수에 객체와 입금액이 전달되면 전달된 객체의 balance(잔액)에 입금액을 누적 저장
// 합니다. 아래에 제시된 클래스 선언과 main() 함수 그리고 실행결과를 참고하여 increaseBy() 함수
// 를 작성하세요.

#include <iostream>

using namespace std;

class Account
{
    int balance; //잔액
public:
    Account(int deposit) : balance(deposit){};
    int getBalance() { return balance; }
    void setBalance(int deposit) { this->balance = deposit; }
    void show()
    {
        cout << "잔액은 " << balance << "원 입니다." << endl;
    }
};

void increaseBy(Account& acc, int in) {
    acc.setBalance(acc.getBalance() + in);
}

int main()
{
    Account acc(500);
    cout << "입금 전 ";
    acc.show();
    int in;
    cout << "입금액 : ";
    cin >> in;
    increaseBy(acc, in);
    cout << "입금 후 ";
    acc.show();
}

// 9. 아래에 제시된 클래스 선언과 main() 함수 그리고 실행결과를 참고하여 전달된 메시지를 출력하기 위한 message_print() 함수를 작성하세요.

#include <iostream>
#include <string>

using namespace std;

void message_print(string&& str) {
    cout << "message = " << str << endl;
}

int main()
{
    string stra = "apple";
    string strb = "banana";
    message_print(move(stra));
    message_print(stra + strb);
    return 0;
}

// 10. 아래에 제시된 클래스 선언과 main() 함수를 참고하여 복사 생성자와 이동 생성자를 구현한 후 출력결과를 예측하세요. 프로그램 수행 결과와 예측 결과를 비교하세요.

#include <iostream>
#include <string>

using namespace std;

class Person
{
    string name;

public:
    Person() = default;
    Person(string n) : name{n} { cout << "생성자 실행" << endl; };
    Person(const Person &person); //복사 생성자
    Person(Person &&p);           //이동 생성자
    ~Person() { cout << "소멸자 실행" << endl; };
    void show(string obj) { cout << obj << " name = " << name << endl; }
};

Person::Person(const Person &person) : name(person.name) {}

Person::Person(Person &&p) {
    this->name = p.name;
    p.name.clear();
}

int main()
{
    cout << "-1----------" << endl;
    Person dan("daniel"); // 생성자 실행
    Person ben = Person("benny"); // 생성자 실행
    cout << "-2----------" << endl;
    Person mvdan = move(dan); // 이동 생성자 실행

    cout << "-3----------" << endl;
    Person cpben = ben; // 복사 생성자 실행
    Person cpmvdan(mvdan); // 복사 생성자 실행
    cout << "-4----------" << endl;
    dan.show("dan"); // 이동 생성자 때문에 아무것도 안나옴
    ben.show("ben"); // benny
    mvdan.show("mvdan"); // daniel
    cpben.show("cpben"); // benny
    cpmvdan.show("cpmvdan"); // daniel
    return 0;
}

// 11. 위 10번 문제 Person class의 멤버변수 string name;을 char *name으로 변경하여 전체 프로그램을 수정하세요. 단 main() 함수의 변경은 없습니다.

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Person
{
    char *name;

public:
    Person() = default;
    Person(const char *n);
    Person(const Person &person); //복사 생성자
    Person(Person &&p);           //이동 생성자
    ~Person();
    void show(string obj);
};

Person::Person(const char *n)
{
    cout << "생성자 실행" << endl;
    this->name = new char[strlen(n) + 1];
    strcpy(name, n);
}

Person::Person(const Person &person)
{
    int len = strlen(person.name);
    this->name = new char[len + 1];
    strcpy(this->name, person.name);
}

Person::Person(Person &&p)
{
    this->name = p.name;
    p.name = nullptr;
}

Person::~Person()
{
    cout << "소멸자 실행" << endl;
    delete[] name;
}

void Person::show(string obj)
{
    cout << obj << " name = ";
    if (name != nullptr)
    {
        cout << name;
    }
    cout << endl;
}

int main()
{
    cout << "20195138 김준호" << endl;
    cout << "-1----------" << endl;
    Person dan("daniel");
    Person ben = Person("benny");
    cout << "-2----------" << endl;
    Person mvdan = move(dan);

    cout << "-3----------" << endl;
    Person cpben = ben;
    Person cpmvdan(mvdan);
    cout << "-4----------" << endl;
    dan.show("dan");
    ben.show("ben");
    mvdan.show("mvdan");
    cpben.show("cpben");
    cpmvdan.show("cpmvdan");
    return 0;
}

