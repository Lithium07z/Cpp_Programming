/*
Cpp_10_가상함수와 추상클래스
*/

/*
1. 오버라이딩에 대하여 설명하세요.
A. 파생 클래스에서 기본 클래스의 가상 함수와 동일한 이름의 함수 선언.
*/

/*
2. 추상 클래스에 대하여 설명하세요.
A. 최소한 하나의 순수 가상 함수를 가진 클래스. 온전한 클래스가 아니므로 객체 생성 불가능 단, 포인터는 선언가능
*/

/*
3. 호출하는 함수의 결정을 실행 시간에 하도록 컴파일러에게 지시하는 키워드는 무엇인가요? 
A. virtual
*/

/*
4. 다음 중 순수 가상 함수는 무엇인가요?
① void paint()=0;
② virtual void paint() { }
③ virtual void paint();
④ virtual void paint()=0; 

A. 4번
*/

/*
5. 다음 중 추상클래스는 무엇인가요?
① class A { void draw()=0; };
② class A { virtual void draw()=0; };
③ abstract class A { void draw(); };
④ class A { virtual void draw() { } };

A. 2번
*/

/*
6. 다음 중 오류가 발생하는 경우를 모두 고르세요.

class Shape {
    public:
        virtual void draw() = 0;
};

class Circle : public Shape {
    public:
        double getArea() { return 3.14; }
};

int main() {
    Shape sh; //1
    Shape *sh; //2
    Circle c; //3
    Circle *c; //4
}

1. 추상 클래스인 Shape를 생성하려 해서 오류 발생
3. Circle 클래스는 추상 클래스인 Shape를 상속받았지만 오버라이딩하지 않았으므로 추상 클래스임,
   따라서 Circle 클래스도 객체 생성이 불가능하므로 오류 발생
*/

/*
7. 밑줄 친 부분을 채워 넣으세요.

class Shape { 
    public:
        virtual void draw(){ cout << "--Shape--"; }
};

class Circle : public Shape {
    public:
        virtual void draw() { 
        _________________1) // 기본 클래스의 draw() 호출
          cout << "Circle" << endl;
};

int main(){
    Shape * pShape = new Circle();
    ______________________2) //기본 클래스 draw() 호출 
}

---------------------------------------------------------

class Shape { 
    public:
        virtual void draw(){ cout << "--Shape--"; }
};

class Circle : public Shape {
    public:
        virtual void draw() { 
        Shape::draw(); // 기본 클래스의 draw() 호출
        cout << "Circle" << endl;
};

int main(){
    Shape * pShape = new Circle();
    pShape->Shape::draw(); //기본 클래스 draw() 호출 
}
*/

/*
8. 제시된 프로그램에 대한 결과를 제시하세요.

#include <iostream>
#include <string>

using namespace std;

class Base {
    public:
        void f() { cout << "Base::f() called" << endl; }
};

class Derived : public Base {
    public: 
        void f() { cout << "Derived::f() called" << endl; }
};

int main(){
    Derived d;
    Derived *pDer = &d;
    pDer->f(); 
    Base *pBase = pDer;
    pBase->f(); 
}

A. [!void f() 앞에 virtual없음!]
Derived::f() called
Base::f() called
*/

/*
9. 주어진 Shape 클래스를 추상클래스로 만들고, Shape 추상 클래스를 상속받는
   파생 클래스를 작성하여 제시된 결과처럼 실행될 수 있도록 프로그램을 완성하세요.

class Shape {
    protected:
        string name; //도형의 이름
        int width, height; //도형이 내접하는 사각형
    public:
        Shape(string n="", int w=0, int h = 0) : name{n}, width{w}, height{h} {}
        string getName() { return name; } //이름 리턴
        virtual double getArea() = 0; //3.14*width*height; //width*height; //width*height/2;
};

//
//필요한 클래스 작성
//

int main() {
    Shape *p[3];
    
    p[0] = new Oval("호떡", 10, 20); 
    p[1] = new Rectangle("노트", 30, 40);
    p[2] = new Triangle("삼각자", 30, 40);
    
    for (int i = 0; i < 3; i++)
    cout << p[i]->getName() << "의 넓이는 " << p[i]->getArea() << endl;
    for (int i = 0; i < 3; i++) delete p[i];
}

-----------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

class Shape {
    protected:
        string name; //도형의 이름
        int width, height; //도형이 내접하는 사각형
    public:
        Shape(string n = "", int w = 0, int h = 0) : name{n}, width{w}, height{h} {}
        string getName() { return name; } //이름 리턴
        virtual double getArea() = 0; //3.14*width*height; //width*height; //width*height/2;
};

class Oval : public Shape {
    public:
        Oval(string n = "", int w = 0, int h = 0) : Shape(n, w, h) {}
        virtual double getArea() { return 3.14 * width * height; }
};

class Rectangle : public Shape {
    public:
        Rectangle(string n = "", int w = 0, int h = 0) : Shape(n, w, h) {}
        virtual double getArea() { return width * height; }
};

class Triangle : public Shape {
    public:
        Triangle(string n = "", int w = 0, int h = 0) : Shape(n, w, h) {}
        virtual double getArea() { return width * height / 2; }
};

int main() {
    Shape *p[3];
    
    p[0] = new Oval("호떡", 10, 20); 
    p[1] = new Rectangle("노트", 30, 40);
    p[2] = new Triangle("삼각자", 30, 40);
    
    for (int i = 0; i < 3; i++)
    cout << p[i]->getName() << "의 넓이는 " << p[i]->getArea() << endl;
    for (int i = 0; i < 3; i++) delete p[i];
}
*/

/*
10. 위 9번 문제를 약간 수정하여 제시된 결과처럼 실행될 수 있도록 프로그램을 완성하세요.

#include <iostream>
#include <string>

using namespace std;

class Shape
{
    Shape *next;
protected:
    string name; //도형의 이름
public:
    Shape(string n = "") : next{NULL}, name{n} {}
    virtual void draw() = 0; // class 명과 name 출력
    
    Shape *add(Shape *s);    // next에 입력된 s도형 저장 후 마지막 도형 반환
    Shape *getNext();        //다음 도형 리턴
};

Shape *Shape::add(Shape *s) { 
    this->next = s;
    this->next->name = s->name;
    return next;
}

Shape *Shape::getNext() { return next; }

class Oval : public Shape {
    public:
        Oval(string n = "") : Shape("Oval" + n) {}
        virtual void draw() {
            cout << name << " -> ";
        }
};

class Rectangle : public Shape {
    public:
        Rectangle(string n = "") : Shape("Rectangle" + n) {}
        virtual void draw() {
            cout << name << " -> ";
        }
        
};

class Triangle : public Shape {
    public:
        Triangle(string n = "") : Shape("Triangle" + n) {}
        virtual void draw() {
            cout << name << " -> ";
        }
};

class Manage
{
public:
    void run()
    {
        Shape *pStart = NULL, *pLast = NULL;
        string choice, namechoice;
        bool startFlag = true;

        while (true)
        {
            cout << "\n생성할 도형을 선택하세요\n o:Oval, r:Rectangle, t:Triangle, 이외:finish : ";
            cin >> choice;
            if (!(choice == "o" || choice == "r" || choice == "t"))
                break;
            
            cout << " 도형의 이름을 입력하세요 : ";
            cin >> namechoice;
            
            switch (startFlag)
            {
            case true:
                if (choice == "o")
                    pStart = new Oval(namechoice);
                else if (choice == "r")
                    pStart = new Rectangle(namechoice);
                else if (choice == "t")
                    pStart = new Triangle(namechoice);
                pLast = pStart;
                startFlag = false;
                break;

            case false:
                if (choice == "o")
                    pLast = pLast->add(new Oval(namechoice));
                else if (choice == "r")
                    pLast = pLast->add(new Rectangle(namechoice));
                else if (choice == "t")
                    pLast = pLast->add(new Triangle(namechoice));
                break;
            }
        }

        cout << "\n연결된 모든 도형 출력" << endl;
        Shape *temp = pStart;
        while (true) {
            if (temp == nullptr) {
                break;
            } else {
                temp->draw();
                temp = temp->getNext();
            }
        }
        cout << "end" << endl;

        cout << "\n연결된 모든 도형 삭제" << endl;
        while (true) {
            if (pStart == nullptr) {
                break;
            } else {
                pStart->draw();
                Shape* temp = pStart;
                pStart = pStart->getNext();
                delete temp;
            }
        }
        cout << "end" << endl;
    }
};

int main()
{
    Manage man;
    man.run();
}
*/

/*
11. 세 개의 입력 신호를 받아 and, or, xor 연산을 수행한 결과를 출력하는 프로그램을 완성하세요. 

//단, 각각의 게이트는 ANDGate, ORGate, XORGate 클래스로 작성하며 AbstractGate를 상속받는다. 
//다형성을 적용한다. 
//논리형 상수 값 출력 시 : cout << boolalpha << true;

class AbstractGate { //추상 클래스
    public:
        virtual bool operation(bool x, bool y, bool z) = 0; // 순수 가상 함수
};

//
//필요한 함수와 클래스 작성
//

class Manage {
    public:
        static void run();
};

void Manage::run() {
    AbstractGate *ag = nullptr;

    int choice;
    bool b1, b2, b3;

    while (true) {
        cout << "\n연산 종류를 선택하세요 1.and, 2.or 3.xor 4.stop>> ";
        cin >> choice;
        if (choice == 4) break; 

        //
        //필요한 구현 내용 작성
        //

    }
}

int main(){
    Manage::run();
}

-------------------------------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

class AbstractGate
{ //추상 클래스
public:
    virtual bool operation(bool x, bool y, bool z) = 0; // 순수 가상 함수
};

class ANDGate : public AbstractGate
{
public:
    virtual bool operation(bool x, bool y, bool z)
    {
        return x * y * z;
    }
};

class ORGate : public AbstractGate
{
public:
    virtual bool operation(bool x, bool y, bool z)
    {
        return x + y + z;
    }
};

class XORGate : public AbstractGate
{
public:
    virtual bool operation(bool x, bool y, bool z)
    {
        if (x == true && y == true && z == true) {
            return true;
        } else if (x == true && y == false && z == false) {
            return true;
        } else if (x == false && y == true && z == false) {
            return true;
        } else if (x == false && y == false && z == true) {
            return true;
        } else {
            return false;
        }
    }
};

class Manage
{
public:
    static void run();
};

void Manage::run()
{
    AbstractGate *ag = nullptr;

    int choice;
    bool b1, b2, b3;

    while (true)
    {
        cout << "\n연산 종류를 선택하세요 1.and, 2.or 3.xor 4.stop>> ";
        cin >> choice;

        if (choice == 4)
        {
            break;
        }

        cout << "(true:1, fales:0) 게이트 입력 값 3개 >> ";
        cin >> b1 >> b2 >> b3;

        if (choice == 3)
        {
            ag = new XORGate();
            cout << "XOR : " << boolalpha << b1 << ", " << boolalpha << b2 << ", " << boolalpha << b3 << " => " << boolalpha << ag->operation(b1, b2, b3) << endl;
        }
        else if (choice == 2)
        {
            ag = new ORGate();
            cout << "OR : " << boolalpha << b1 << ", " << boolalpha << b2 << ", " << boolalpha << b3 << " => " << boolalpha << ag->operation(b1, b2, b3) << endl;
        }
        else if (choice == 1)
        {
            ag = new ANDGate();    
            cout << "AND : " << boolalpha << b1 << ", " << boolalpha << b2 << ", " << boolalpha << b3 << " => " << boolalpha << ag->operation(b1, b2, b3) << endl;
        }
    }
}

int main()
{
    Manage::run();
}
*/

/*
cpp_11_템플릿과 STL
*/

/*
1. 다음 질문에 O, X로 답하세요. 

A. 템플릿을 선언하기 위해 사용하는 키워드는 template 이다. (O)

B. 제네릭 타입을 선언하는 키워드는 generic 이다. (X)

C. 템플릿 함수와 동일한 이름의 함수가 중복되어 있을 경우 템플릿 함수가 우선적으로 바인딩 된다. (X)

D. C++ 표준STL 라이브러리가 작성된 이름공간은 std 이다. (O)

E. 템플릿 함수나 템플릿 클래스를 활용하는 프로그래밍 기법을 일반화(generic) 프로그래밍이라고 한다. (O)

F. 템플릿 함수는 오버로딩을 할 수 없다. (O)

G. 두 값을 그룹으로 묶는 클래스는 pair 이다. (O)

H. map 컨테이너 요소들은 키값을 기준으로 내림차순으로 정렬된다. (X)

I. set 컨테이너 요소들은 ‘키’로 ‘값’을 검색 한다. (X)

J. 벡터 v의 각 원소에 대해 print()를 호출 하려면 for_each(v.begin(), v.end(), print);를 사용한다. (O)

K. 람다식에서 리턴타입은 생략할 수 있다. (O)

L. 람다식에서 함수 바깥의 변수 목록을 사용하려면 캡쳐리스트([ ])로 작성하면 된다. (O)

*/

/*
2. 다음 제네릭 함수 선언에서 잘못된 부분을 바르게 수정하세요.

template <typename T> 
int max(T x, T y) {
    if(x > y) return x;
    else return y;
}

int를 T로 바꾸거나 declType(auto)로 수정
*/

/*
3. main() 함수가 실행 될 수 있도록 다음 두 get() 함수를 일반화한 하나의 제네릭 get() 함수로 작성하세요.

int get(int a[], int size, int index) { 
    if(index >=0 && index < size) return a[index];
    else return 0;
}

char get(char *a, int size, int index) {
    if(index >=0 && index < size) return *(a+index);
    else return 0;
}

int main(){ 
    const char carr [] = "daniel";
    int iarr [] = {1,2,3};

    cout << get(carr, sizeof(carr)/sizeof(char), 4) << endl;
    cout << get(iarr, sizeof(iarr)/sizeof(int), 4) << endl;

    return 0;
}

-----------------------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

template<typename T>
T get(T a[], int size, int index)
{
    if (index >= 0 && index < size)
        return a[index];
    else
        return 0;
}

template<>
char get(char *a, int size, int index)
{
    if (index >= 0 && index < size)
        return *(a + index);
    else
        return 0;
}

int main()
{
    const char carr[] = "daniel";
    int iarr[] = {1, 2, 3};

    cout << get(carr, sizeof(carr) / sizeof(char), 4) << endl;
    cout << get(iarr, sizeof(iarr) / sizeof(int), 4) << endl;

    return 0;
}
*/

/*
4. 다음에서 템플릿 선언을 잘못한 것은?

A. template <class T>
B. template (class T)
C. template <typename T>
D. template <typename T1, typename T2>

B번
*/

/*
5. C++ 다음 STL의 각 기능을 사용하기 위해 필요한 헤더 파일을 제시하세요. 
A. vector 클래스 
B. merge() 함수 
C. map 클래스

A. #include<vector>
B. #include<algorithm>
C. #include<map>
*/

/*
8. vector<double> v; 일 때, 제시된 문제를 해결하는 문장을 제시하세요. 

A. 생성된 벡터 v 마직막에 3.1 삽입 
v.emplace_back(3.1);

B. 벡터 v에 저장된 원소 개수 
v.size();

C. 벡터 v에 저장된 첫 번째 원소 삭제
v.erase(v.begin(), v.begin() + 1);
*/

/*
12. 다음 소스의 빈칸을 채워 람다식을 완성하세요. 빈칸은 auto 변수인 method에 매개변수로 배열의 
    크기(size)와 int 타입의 배열(arr)을 받아 오름차순으로 정렬하는 람다식입니다.

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ____________________________________________ { //람다식 완성
    sort(arr, arr+size);
};
 
    int iarr[] = {4, 7, 2, 67, 4, 13, 6};
    method(sizeof(iarr)/sizeof(int), iarr);
    for(auto value : iarr){
        cout<<value<<" ";
    }
    cout<<endl;
    return 0;
}

-----------------------------------------------------------------

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    auto method = [](int size, int arr[])
    {   //람다식 완성
        sort(arr, arr + size);
    };

    int iarr[] = {4, 7, 2, 67, 4, 13, 6};
    method(sizeof(iarr) / sizeof(int), iarr);
    for (auto value : iarr)
    {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}
*/

/*
13. main() 함수와 실행결과를 참고하여 배열의 순서를 역순으로 할 수 있는 템플릿 함수 reverse()와 
    swap() 함수를 작성합니다. 데이터를 교환하는 템플릿 함수, 배열의 요소를 출력하는 템플릿 함수
    도 함께 만들어서 활용합니다.

#include <iostream>
#include <string>

using namespace std;

namespace swaping {
    template<typename T>
    void swap(T& x, T& y) {
        T temp = x;
        x = y;
        y = temp;
    }
}
//swap() :매개변수로 전달된 두 데이터를 교환

template<typename T>
void reverse(T arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        swaping::swap(arr[i], arr[size - 1 - i]);
    }
}

template <>
void reverse(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (i == size / 2) {
            break;
        }
        swaping::swap(arr[i], arr[size - 1 - i]);
    }
}
// reverse() : 전달 받은 배열의 양 끝 데이터를 순차적(첫 번째와 마지막, 두 번째와 마지막에서 두번째...)으로 swap()의 매개변수로 전달

template <typename T>
void print(string title, T arr[], int size)
{
    cout << title << " : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[] = {3, 7, 2, 12, 14, 1};
    double arr2[] = {22.7, 14.2, 3.8, 12.23, 11.2};
    char arr3[] = {'C', 'a', 'B', 'E', 'N', 'Q'};
    string arr4[] = {"John", "Lu", "Mary", "Su"};

    print("Original array", arr1, sizeof(arr1) / sizeof(int));
    reverse(arr1, sizeof(arr1) / sizeof(int));
    print("Reversed array", arr1, sizeof(arr1) / sizeof(int));
    cout << endl;

    print("Original array", arr2, sizeof(arr2) / sizeof(double));
    reverse(arr2, sizeof(arr2) / sizeof(double));
    print("Reversed array", arr2, sizeof(arr2) / sizeof(double));
    cout << endl;

    print("Original array", arr3, sizeof(arr3) / sizeof(char));
    reverse(arr3, sizeof(arr3) / sizeof(char));
    print("Reversed array", arr3, sizeof(arr3) / sizeof(char));
    cout << endl;

    print("Original array", arr4, sizeof(arr4) / sizeof(string));
    reverse(arr4, sizeof(arr4) / sizeof(string));
    print("Reversed array", arr4, sizeof(arr4) / sizeof(string));
    cout << endl;

    return 0;
}
*/

/*
14. main() 함수와 실행결과를 참고하여 벡터를 사용하여 Sudent 정보를 저장하고 출력하는 프로그램을 완성 하세요.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
    string name;
    int id;
public:
    Student() = default;
    Student(string name, int id) : name(name), id(id){};
    ~Student() = default;
    void show() { cout << "name: " << name << ", id: " << id << endl; }
};

class Manager
{
    vector<Student> vec;

public:
    void run();
    void input2save();
    void print(); // show()함수를 이용하여 vec에 저장된 모든 Student 객체 정보 출력
};

void Manager::run()
{
    cout << ">> 벡터에 학생 데이터를 저장합니다." << endl;
    input2save();
    cout << ">> 벡터에 저장된 모든 학생 데이터를 출력합니다." << endl;
    print();
}

void Manager::input2save()
{
    string name;
    string id;

    while (true) {
        cout << "name : ";
        getline(cin, name);   
        
        if (name == "quit") {
            break;
        }

        cout << "id : ";
        cin >> id;

        vec.emplace_back(name, stoi(id)); // vector<Student*>라면 vec.emplace_back(new Student(name, stoi(id)));
    }
    cout << vec.size() << " 명의 학생이 저장되었습니다." << endl; 
    // Student 객체와 관련된 정보를 입력 받아 vec에 저장
}

void Manager::print()
{
    for (Student& temp : vec) {
        temp.show();
    }
    // show()함수를 이용하여 vec에 저장된 모든 Student 객체 정보 출력
}

int main()
{
    Manager man;
    man.run();
}
*/

/*
15. 국가의 수도 맞추기 게임을 vector를 사용하여 작성합니다. 
- Nation 클래스는 국가와 수도를 문자열 멤버변수로 저장합니다. 
- vector<Nation> v;로 생성한 벡터는 국가와 수도가 저장된 Nation 타입의 객체를 저장합니다.
- 프로그램 내에서 벡터에 Nation 객체를 여러 개 미리 저장하여 사용합니다. 
Nation n[] = { 
    Nation("미국", "워싱턴"), Nation("영국", "런던"), Nation("프랑스", "파리"), 
    Nation("중국", "베이징"), Nation("일본", "도쿄"), Nation("러시아", "모스크바"), 
    Nation("브라질", "브라질리아"), Nation("독일", "베를린"), Nation("멕시코", "멕시코시티") 
};
- vector<Nation>v는 국가와 수도를 입력 받아 새로운 객체를 추가 할 수도 있습니다.
- vector<Nation>v에 저장된 데이터를 이용하여 랜덤하게 데이터를 꺼내 퀴즈를 볼 수도 있습니다.

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Nation
{
    string nation;  //나라이름
    string capital; //수도
public:
    Nation(string nation, string capital)
    {
        this->nation = nation;
        this->capital = capital;
    }
    string getCapital() { return capital; }
    string getNation() { return nation; }
    void show()
    {
        cout << '(' << nation << ',' << capital << ')';
    }
};

class NationGame
{
    vector<Nation> v;
    void input();
    void list();
    void quiz();
    bool exist(string nation);

public:
    NationGame();
    void run();
};

NationGame::NationGame()
{
    Nation n[] = {
        Nation("미국", "워싱턴"), Nation("영국", "런던"), Nation("프랑스", "파리"), 
        Nation("중국", "베이징"), Nation("일본", "도쿄"), Nation("러시아", "모스크바"), 
        Nation("브라질", "브라질리아"), Nation("독일", "베를린"), Nation("멕시코", "멕시코시티")
    };

    for (int i = 0; i < 9; i++)
        v.emplace_back(n[i]); // v.push_back(n[i]);

    srand((unsigned)time(0)); // 시작할 때마다, 다른 랜덤수를 발생시키기 위한 seed 설정
}

void NationGame::run()
{
    cout << "***** 국가의 수도 맞추기 게임을 시작합니다. *****" << endl;
    while (true)
    {
        int cmd;
        cout << "\n1(정보 입력), 2(퀴즈), 3(종료) : ";
        cin >> cmd;
        switch (cmd)
        {
        case 1:
            input();
            break;
        case 2:
            quiz();
            break;
        case 3:
            return;
        }
    }
}

void NationGame::quiz()
{
    while (true)
    {
        int index = rand() % v.size(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수가 n에 발생
        string input;

        cout << v[index].getNation() << "의 수도는? ";
        cin >> input;

        if (input == "quit") {
            break;
        }

        if (v[index].getCapital() == input) {
            cout << "Correct !!" << endl;
        } else {
            cout << "NO !!" << endl;
        }
    }
}

void NationGame::input()
{
    string nation, capital;

    cout << "현재 " << v.size() << "개의 나라가 입력되어 있습니다." << endl;
    cout << "\n국가와 수도를 입력하세요(quit quit이면 입력 종료)" << endl;

    while (true)
    {
        cout << v.size() + 1 << " : ";
        cin >> nation >> capital;

        if (nation == "quit" && capital == "quit") {
            break;
        }
        
        if (exist(nation)) {
            cout << "already exists!!" << endl;
            continue;
        } else {
            v.emplace_back(nation, capital);
        }
    }
}

bool NationGame::exist(string nation)
{
    for (Nation temp : v) {
        if (temp.getNation() == nation) {
            return true;
        }
    }
    return false;
}

int main()
{
    NationGame game;
    game.run();
}
*/
