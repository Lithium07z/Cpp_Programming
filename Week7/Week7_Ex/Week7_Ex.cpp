// 3. 다음 프로그램의 실행 결과를 제시하세요.
// 20

// 4. 다음 코드의 실행 결과를 제시하세요.
// 7
// 15

// 5. 제시된 클래스에 대하여 질문에 답하세요.
// A. Rec 클래스에 대한 포인터 변수 p를 선언한 후 p에 객체 r의 주소를 지정하세요.
// >  Rec *p; p = &r;
// B. 포인터 변수 p를 이용하여 write 함수를 호출할 수 있는 두 가지 방법을 제시하세요.
// >  p->write(); or (*p).write();
// C. 크기가 4인 Rec 객체 배열 arr를 동적으로 생성하는 문장을 new연산자를 사용하여 제시하세요.
// >  Rec *arr = new Rec[4];
// D. 크기가 4인 Rec 객체 배열 arr를 동적으로 생성하는 문장을 공유가 허락되지 않는 스마트 포인터를 사용하여 제시하세요.
// >  unique_ptr<Rec[]> arr = make_unique<Rec[]>(4);
// E. 위 D번에서 new 연산자로 할당 받은 동적메모리를 반환하는 문장을 제시하세요.
// >  delete [] arr;
// F. D번에서 생성된 배열 arr에서 배열 원소 두 번째에 저장된 객체의 write() 멤버 함수를 호출하는 문장을 두 가지 방법으로 제시하세요. 단, 배열 원소 참조 시 []는 사용하지 않습니다.
// >  (*(arr + 1)).write(); or (arr + 1)->write();
// G. 크기가 3인 Rec 객체 배열 dim을 동적으로 할당하면서 매개변수가 있는 생성자를 사용하여 초기화하는 문장을 제시하세요. 단, 초기화 값은 본인이 임의로 결정합니다. 
// >  Rec *dim = new Rec[3] { Rec(0, 1), Rec(1, 2), Rec(2, 3) };
// H. Rec array[] = { Rec(13,6), Rec(5,8), Rec(3,12) };와 같이 초기화 된 객체 배열을 사용하여 멤버 함수 write()를 호출하는 문장을 제시하세요. 단, 범위 기반 for를 사용하세요. 
// >  for (Rec temp : array) { temp.write(); }

// 7. 아래 설명에 해당하는 배열을 생성하고, 실행 화면처럼 동작하는 프로그램을 작성하세요.
// - 사용자로부터 배열의 크기를 입력 받아, 실수를 저장할 수 있는 배열을 동적 할당 받습니다.
// - 이후, 배열의 크기만큼 실수 값을 입력 받아 배열에 저장합니다.
// - 동적 배열의 생성은 vector를 이용하는 방법과 new를 이용하는 방법 모두 구현합니다.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int size;

    cout << "array size? ";
    cin >> size;

    vector<double> varr(size);
    cout << "== vector array ==" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "value? ";
        cin >> varr.at(i);
    }

    for (int i = 0; i < size; i++)
    {
        cout << "varr[" << i << "]=" << varr.at(i) << endl;
    }

    double *arr = new double[size];
    cout << "== new array ==" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "value? ";
        cin >> arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        cout << "narr[" << i << "]=" << arr[i] << endl;
    }

    delete [] arr;
}

// 8. 주어진 main() 함수와 실행 화면을 참고하여 배열을 조금 더 쉽게 사용할 수 있는 Array 클래스를 작성하고, 실행 화면처럼 동작하는 프로그램을 작성하세요.
// - Array 클래스는 데이터 멤버로 capacity, size, arr을 갖습니다.
// : capacity(데이터를 담을 수 있는 최대 용량)
// : size(데이터가 저장된 수)
// : arr(힙에 생성한 배열의 첫 번째 요소를 가리키는 포인터)
// - Array 클래스는 배열 마지막 위치에 데이터를 추가하는 멤버 함수 insert()를 갖습니다.
// - capacity를 넘겨 데이터를 추가하려고 할 경우에는 ‘배열이 가득 차 추가할 수 없다’는 메시지를 출력합니다.
// - 배열의 내용을 출력하는 멤버 함수 print()도 갖습니다.

#include <iostream>

using namespace std;

class Array
{
    int capacity;
    int size = 0;
    int *arr;

public:
    Array(int capacity) : capacity{capacity} { arr = new int[capacity]; };
    ~Array() { delete [] arr; };
    void insert(int value);
    void print();
};

void Array::insert(int value)
{
    if (capacity <= size)
    {
        cout << "데이터 " << value << "는 추가할 수 없습니다. 배열이 가득 찼습니다.";
    }
    else
    {
        arr[size++] = value;
    }
}

void Array::print()
{
    cout << "arr = ";
    for (int i = 0; i < size; i++)
    {
        cout << "   " << arr[i];
    }
    cout << endl;
}

int main()
{
    int count;
    cout << "array size? ";
    cin >> count;

    Array array1(count); //크기가 count인 배열 생성

    for (int i = 0; i < count; i++)
    {
        array1.insert(i + 10);
    }
    array1.print();
    array1.insert(34);
    cout << endl;
    return 0;
}

// 9. 제시된 클래스를 사용하여 실행 화면과 같이 동작하는 프로그램을 작성하세요. Pizza 객체 배열은 입력 받은 피자 판의 개수만큼 new를 이용하여 동적으로 생성합니다.
// main()에서 처리
// Pizza class를 만들고 메인함수에서 오버라이딩하고 초기화 및 구동
#include <iostream>
#include <string>

using namespace std;

class Pizza
{
    string *size;

public:
    Pizza() = default;
    ~Pizza() { delete size; cout << "소멸자 I had it all." << endl; };
    void setSize(string s); // s를 size에 대입
    string getSize();
};

void Pizza::setSize(string s) {
    this->size = new string(s);
}

string Pizza::getSize() {
    return *size;
}

int main()
{
    int count = 0;
    string size;
    Pizza *parr;
    cout << "피자 몇 판? ";
    cin >> count;

    parr = new Pizza[count];

    cout << "피자 크기는(small, medium, large)? ";
    cin >> size;

    for (int i = 0; i < count; i++) {
        parr[i].setSize(size);
    }

    for (int i = 0; i < count; i++) {
        cout << i << ") " << parr[i].getSize() << " Pizza Yammy" << endl;
    }

    cout << endl;
    delete [] parr;
    return 0;
}

// PizzaManager 사용
// Pizza 클래스가 헤더파일의 역할을, PizzaManager가 구동파일 역할을 하게됨
// 정보은닉, 코드수정 용이, 상속 등의 장점을 가짐 
#include <iostream>
#include <string>

using namespace std;

class Pizza
{
    string *size;
public:
    Pizza() = default;
    ~Pizza();
    void setSize(string s); // s를 size에 대입
    string getSize();
};

Pizza::~Pizza()
{
    delete size;
    cout << "소멸자 I Had it all." << endl;
}

void Pizza::setSize(string s) { Pizza::size = new string(s); }
string Pizza::getSize() { return *Pizza::size; }

class PizzaManager
{
    int count;
    Pizza *p;
    string sml;

public:
    PizzaManager()
    {
        cout << "피자 몇 판? ";
        cin >> count;

        p = new Pizza[count]; //객체 생성 - 디폴트생성자`
        
        cout << "피자 크기는(small, medium, large)? ";
        cin >> sml;
        
        for (int i = 0; i < count; i++)
        {
            p[i].setSize(sml);
        }
    }
    void status()
    {
        // Pizza 클래스 타입의 배열의 각 요소마다 getSize() 호출
        for (int i = 0; i < count; i++)
        {
            cout << i << ") " << p[i].getSize() << " Pizza Yammy" << endl;
        }
        cout << endl;
    }
    ~PizzaManager()
    {
        delete[] p; //멤버 메모리 해제
    }
};

int main()
{
    PizzaManager pm;
    pm.status(); // Pizza 클래스 타입의 배열의 각 요소마다 getSize() 호출 return 0;
}

// 10. 주어진 main() 함수와 실행 화면을 참고하여 Person 클래스를 완성하세요.

#include <memory>
#include <iostream>

using namespace std;

class Person {
    string name;
    int age;
public:
    Person(string name, int age) : name{name}, age{age} {};
    ~Person() { cout << "메모리 해제" << endl; };
    void disPlay(string p);
    void changeName(string name);
};

void Person::disPlay(string p) {
    cout << p << ") name = " << this->name << ", age = " << this->age << endl;
}

void Person::changeName(string name) {
    this->name = name;
}

int main()
{
    auto p1 = std::make_shared<Person>("benny", 17);
    p1->disPlay("p1");
    std::cout << "main() : p1.use_count() : " << p1.use_count() << std::endl;
   
    std::shared_ptr<Person> p2 = p1;
    p2->changeName("daniel");

    p1->disPlay("p1");
    p2->disPlay("p2");
    std::cout << "main() : p1.use_count() : " << p1.use_count() << std::endl;
}

// 11. 다음 프로그램의 동작을 확인하여 문제가 있는 경우 문제점을 설명하고 해결 방법을 제시하세요.

#include <memory>
#include <iostream>

using namespace std;

class Person
{
    string name;
    int age;

public:
    shared_ptr<Person> twins;
    
    Person(string n, int a) : name(n), age(a){};
   
    ~Person()
    {
        cout << name << "메모리 해제" << endl;
    }
    void disPlay() { cout << "name = " << name << ", age = " << age; }
};

void show(shared_ptr<Person> sp)
{
    sp->disPlay();
    cout << ", show().sp.use_count() = " << sp.use_count() << endl;
}

int main()
{
    auto tw1 = make_shared<Person>("daniel", 20);
    auto tw2 = make_shared<Person>("benny", 20);
    show(tw1);
    show(tw2);
    cout << endl;
    cout << "main : tw1.use_count() = " << tw1.use_count() << endl;
    cout << "main : tw2.use_count() = " << tw2.use_count() << endl;
    cout << endl;
    tw1->twins = tw2;
    tw2->twins = tw1;
}

// tw1->twins = tw2; tw2->twins = tw1; 두 줄 때문에 문제가 발생한다 이 두 줄은 순환참조를 만들어
// shared포인터의 use_count()가 감소하지 못하게 만들기 때문에 shared포인터가 정상적으로 해제될 수 없게 한다.
// twins를 weak_ptr로 만들면 된다.