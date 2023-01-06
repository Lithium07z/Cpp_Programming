// 2. Exam 클래스의 주석에 해당하는 프렌드 선언문을 작성하세요.
bool isCheck(int i, Exam e);

class ExamMember
{
    void em_method(Exam e);
};

class Exam
{
    friend bool isCheck(int i, Exam e); //외부함수를 isCheck()를 프렌드로 선언
    friend void ExamMember::em_method(Exam e); // ExamMember 클래스의 멤버 함수 em_method()를 프렌드로 선언
    friend ExamMember; // ExamMember 클래스 전체를 프렌드로 선언
};

/* 3. Power 객체가 다음과 같을 경우, Power 객체 각 멤버에 대한 다음 연산을 위한 연산자 함수를 작성하세요.
class Power { //에너지를 표현하는 파워 클래스
    int kick; //발로 차는 힘
    int punch; //주먹으로 치는 힘
public: 
    Power(int kick=0, int punch=0) { 
       this->kick = kick;
       this->punch = punch;
    }
}; 

A. c = a + b; //a, b, c는 Power 객체 //멤버 함수로 작성

Power Power::operator+(const Power& b) { // Power b나 cosnt Power& b나 상관X const Power& b가 더 안전함
    Power temp;
    temp.kick = this->kick + b.kick;
    temp.punch = this->punch + b.punch;
    return temp;
}

B. c = a + b; //a, b, c는 Power 객체 //프렌드로 사용할 연산자 함수로 작성

class Power
{              //에너지를 표현하는 파워 클래스
    int kick;  //발로 차는 힘
    int punch; //주먹으로 치는 힘
public:
    friend Power operator+(const Power& a, const Power& b);
    Power(int kick = 0, int punch = 0)
    {
        this->kick = kick;
        this->punch = punch;
    }
};

Power operator+(const Power& a, const Power& b) {
    Power temp;
    temp.kick = a.kick + b.kick;
    temp.punch = a.punch + b.punch;
    return temp;
}

C. b = a + 2; //a, b는 Power 객체 //멤버 함수로 작성

class Power
{              //에너지를 표현하는 파워 클래스
    int kick;  //발로 차는 힘
    int punch; //주먹으로 치는 힘
public:
    Power operator+(int a);

    Power(int kick = 0, int punch = 0)
    {
        this->kick = kick;
        this->punch = punch;
    }
};

Power Power::operator+(int a) {
    Power temp;
    temp.kick = this->kick + a;
    temp.punch = this->punch + a;
    return temp;
}

D. b = 2 + a; //a, b는 Power 객체 //프렌드로 사용할 연산자 함수로 작성

class Power
{              //에너지를 표현하는 파워 클래스
    int kick;  //발로 차는 힘
    int punch; //주먹으로 치는 힘
public:
    friend Power operator+(int a, const Power& b);
    Power(int kick = 0, int punch = 0)
    {
        this->kick = kick;
        this->punch = punch;
    }
};

Power operator+(int a, const Power& b) { // Power 객체에 대한 변동이 없으므로 Power&선언 하는 것이 안전함
    Power temp;
    temp.kick = a + b.kick;
    temp.punch = a + b.punch;
    return temp;
}

E. a == b; //a, b는 Power 객체 //멤버 함수로 작성

class Power
{              //에너지를 표현하는 파워 클래스
    int kick;  //발로 차는 힘
    int punch; //주먹으로 치는 힘
public:
    bool operator==(const Power& b);
    Power(int kick = 0, int punch = 0)
    {
        this->kick = kick;
        this->punch = punch;
    }
};

bool Power::operator==(const Power& b) { // Power 객체에 대한 변동이 없으므로 Power&선언 하는 것이 안전함
    if (this->kick == b.kick && this->punch == b.punch) {
        return true;
    }
    else 
    {
        return false;    
    }
}

F. a += b; //a, b는 Power 객체 //멤버 함수로 작성

class Power
{              //에너지를 표현하는 파워 클래스
    int kick;  //발로 차는 힘
    int punch; //주먹으로 치는 힘
public:
    Power& operator+=(const Power& b);
    Power(int kick = 0, int punch = 0)
    {
        this->kick = kick;
        this->punch = punch;
    }
};

Power& Power::operator+=(const Power& b) { // Power 객체에 대한 변동이 없으므로 Power&선언 하는 것이 안전함
    this->kick = this->kick + b.kick;
    this->punch = this->punch + b.punch;
    return *this;
}

G. a = b; //a, b는 Power 객체 //멤버 함수로 작성

class Power
{              //에너지를 표현하는 파워 클래스
    int kick;  //발로 차는 힘
    int punch; //주먹으로 치는 힘
public:
    Power& operator=(const Power& a);
    friend void swap_power(Power& a, Power& b);
    Power(int kick = 0, int punch = 0)
    {
        this->kick = kick;
        this->punch = punch;
    }
};

Power& Power::operator=(const Power& b) {
    if (this == &b) {
        return *this;
    }
    Power temp(b);
    swap_power(*this, temp);
    return *this;
}

void swap_power(Power& a, Power& b) {
    swap(a.kick, b.kick);
    swap(a.punch, b.punch);
}

H. p = createObject(); //a는 Power 객체 //멤버 함수로 작성

class Power
{              //에너지를 표현하는 파워 클래스
    int kick;  //발로 차는 힘
    int punch; //주먹으로 치는 힘
public:
    Power(const Power& a);
    Power& operator=(const Power&& a);
    friend void swap_power(Power& a, Power& b);
    Power(int kick = 0, int punch = 0)
    {
        this->kick = kick;
        this->punch = punch;
    }
};

Power& Power::operator=(const Power&& b) {
    Power temp(b);
    swap_power(*this, temp);
    return *this;
}

void swap_power(Power& a, Power& b) {
    swap(a.kick, b.kick);
    swap(a.punch, b.punch);
}

I. ++a; //a는 Power 객체 //멤버 함수로 작성

class Power
{              //에너지를 표현하는 파워 클래스
    int kick;  //발로 차는 힘
    int punch; //주먹으로 치는 힘
public:
    Power& operator++();
    Power(int kick = 0, int punch = 0)
    {
        this->kick = kick;
        this->punch = punch;
    }
};

Power& Power::operator++() {
    this->kick++;
    this->punch++;
    return *this;
}

J. ++a; //a는 Power 객체 //프렌드로 사용할 연산자 함수로 작성

class Power
{              //에너지를 표현하는 파워 클래스
    int kick;  //발로 차는 힘
    int punch; //주먹으로 치는 힘
public:
    friend Power& operator++(Power& a);
    Power(int kick = 0, int punch = 0)
    {
        this->kick = kick;
        this->punch = punch;
    }
};

Power& operator++(Power& a) {
    a.kick++;
    a.punch++;
    return a;
}

K. a++; //a는 Power 객체 //멤버 함수로 작성

class Power
{              //에너지를 표현하는 파워 클래스
    int kick;  //발로 차는 힘
    int punch; //주먹으로 치는 힘
public:
    Power& operator++(int x);
    Power(int kick = 0, int punch = 0)
    {
        this->kick = kick;
        this->punch = punch;
    }
};

Power Power::operator++(int x) {
    Power temp = *this;
    this->kick++;
    this->punch++;
    return temp;
}

L. a++; //a는 Power 객체 //프렌드로 사용할 연산자 함수로 작성

class Power
{              //에너지를 표현하는 파워 클래스
    int kick;  //발로 차는 힘
    int punch; //주먹으로 치는 힘
public:
    friend Power operator++(Power& a, int x);
    Power(int kick = 0, int punch = 0)
    {
        this->kick = kick;
        this->punch = punch;
    }
};

Power operator++(Power& a, int x) {
    Power temp(a);
    a.kick++;
    a.punch++;
    return temp;
}

M. ! //a는 Power 객체, 모든 멤버 값이 0이면 true리턴 //멤버 함수로 작성

class Power
{              //에너지를 표현하는 파워 클래스
    int kick;  //발로 차는 힘
    int punch; //주먹으로 치는 힘
public:
    bool operator!();
    Power(int kick = 0, int punch = 0)
    {
        this->kick = kick;
        this->punch = punch;
    }
};

bool Power::operator!() {
    if (this->kick == 0 && this->punch == 0) {
        return true;
    } else {
        return false;
    }
}

*/

//4. Power 객체가 다음과 같을 경우, Power 객체 각 멤버에 대한 *연산이 가능하도록 연산자 함수를 멤버함수와 외부 함수로 각각 제시하세요.
/*
class Power
{              //에너지를 표현하는 파워 클래스
    int kick;  //발로 차는 힘
    int punch; //주먹으로 치는 힘
public:
    Power(int kick = 0, int punch = 0)
    {
        this->kick = kick;
        this->punch = punch;
    }
    void show(string obj);
};

void Power::show(string obj)
{
    cout << obj << ") kick=" << kick << ',' << "punch=" << punch << endl;
}

int main()
{
    Power a(3, 5), b(4, 6), c;
    c = a * b;
    a.show("a");
    b.show("b");
    c.show("c");
}
*/

// 멤버함수
class Power
{              //에너지를 표현하는 파워 클래스
    int kick;  //발로 차는 힘
    int punch; //주먹으로 치는 힘
public:
    Power operator*(const Power& b);
    Power(int kick = 0, int punch = 0)
    {
        this->kick = kick;
        this->punch = punch;
    }
    void show(string obj);
};

Power Power::operator*(const Power& b) {
    Power temp;
    temp.kick = this->kick * b.kick;
    temp.punch = this->punch * b.punch;
    return temp;
}

// 외부함수
class Power
{              //에너지를 표현하는 파워 클래스
    int kick;  //발로 차는 힘
    int punch; //주먹으로 치는 힘
public:
    friend Power operator*(const Power& a, const Power& b);
    Power(int kick = 0, int punch = 0)
    {
        this->kick = kick;
        this->punch = punch;
    }
    void show(string obj);
};

Power operator*(const Power& a, const Power& b) {
    Power temp;
    temp.kick = a.kick * b.kick;
    temp.punch = a.punch * b.punch;
    return temp;
}

// 5. Power 객체의 kick과 punch에 2n 곱하기 연산을 수행하는 << 연산자를 멤버 함수로 작성하세요.
/*
int main() {
    Power a(2,3);
    a << 3;
    a.show("a");
    Power b(1,5);
    b << 1;
    b.show("b");
}
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Power
{              //에너지를 표현하는 파워 클래스
    int kick;  //발로 차는 힘
    int punch; //주먹으로 치는 힘
public:
    Power& operator<<(int x);
    Power(int kick = 0, int punch = 0)
    {
        this->kick = kick;
        this->punch = punch;
    }
    void show(string obj);
};

Power& Power::operator<<(int x) {
    this->kick = this->kick * pow(2, x);
    this->punch = this->punch * pow(2, x);
    return *this;
}

void Power::show(string obj)
{
    cout << obj << ") kick=" << kick << ',' << "punch=" << punch << endl;
}

int main()
{
    Power a(2, 3);
    a << 3;
    a.show("a");
    Power b(1, 5);
    b << 1;
    b.show("b");
}

// 6. Book 객체에 대하여 다음과 같은 연산을 수행할 수 있도록 연산자 함수를 멤버 함수로 구현하고 프로그램을 완성 하세요.
/*
class Book
{
    string title;
    int price;
public:
    Book(string title = "", int price = 0);
    void show(string obj);
    string getTitle(); // title 반환
};

int main()
{
    Book a("청춘", 20000), b("미래", 30000);
    a += 500; //책 a의 가격 500원 증가
    b -= 500; //책 b의 가격 500원 감소
    a.show("a");
    b.show("b");
    Book c("명품 C++", 30000), d("고품 C++", 30000);
    if (c == 30000)
        cout << "명품 C++ 정가 30000원" << endl; // price 비교
    if (c == "명품 C++")
        cout << "명품 C++ 입니다." << endl; //책 title 비교
    if (c == d)
        cout << "두 책이 같은 책입니다." << endl; // title, price 모두 비교
    else
        cout << "두 책이 다른 책입니다." << endl;
}
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Book
{
    string title;
    int price;
public:
    Book& operator+=(int x);
    Book& operator-=(int x);
    bool operator==(const Book& a);
    bool operator==(string a);
    bool operator==(int a);
    Book(string title = "", int price = 0);
    void show(string obj);
    string getTitle(); // title 반환
};

Book& Book::operator+=(int x) {
    this->price += x;
    return *this;
}

Book& Book::operator-=(int x) {
    this->price -= x;
    return *this;
}

bool Book::operator==(const Book& a) {
    if (this->title == a.title && this->price == a.price) {
        return true;
    } else {
        return false;
    }
}

bool Book::operator==(string a) {
    if (this->title == a) {
        return true;
    } else {
        return false;
    }
}

bool Book::operator==(int a) {
    if (this->price == a) {
        return true;
    } else {
        return false;
    }
}

Book::Book(string title, int price) {
    this->title = title;
    this->price = price;
}

void Book::show(string obj)
{
    cout << obj << ") title=" << title << ',' << "punch=" << price << endl;
}

string Book::getTitle() {
    return this->title;
}

int main()
{
    Book a("청춘", 20000), b("미래", 30000);
    a += 500; //책 a의 가격 500원 증가
    b -= 500; //책 b의 가격 500원 감소
    a.show("a");
    b.show("b");
    Book c("명품 C++", 30000), d("고품 C++", 30000);
    if (c == 30000)
        cout << "명품 C++ 정가 30000원" << endl; // price 비교
    if (c == "명품 C++")
        cout << "명품 C++ 입니다." << endl; //책 title 비교
    if (c == d)
        cout << "두 책이 같은 책입니다." << endl; // title, price 모두 비교
    else
        cout << "두 책이 다른 책입니다." << endl;
}

// 7. Matrix 클래스에 대하여 다음과 같은 연산이 가능하도록 연산자 함수를 멤버 함수로 구현하고 프로그램을 완성하세요.

#include <iostream>
#include <string>

using namespace std;

class Matrix
{
    int ar[4];

public:
    Matrix(int a1 = 0, int a2 = 0, int b1 = 0, int b2 = 0);
    Matrix operator+(Matrix a);
    Matrix& operator+=(Matrix a);
    void operator>>(int a[]);
    Matrix& operator<<(int a[]);
    void show(string name);
};

Matrix::Matrix(int a1, int a2, int b1, int b2) {
    ar[0] = a1; ar[1] = a2; ar[2] = b1; ar[3] = b2;
}

Matrix Matrix::operator+(Matrix a) {
    Matrix temp;
    for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
        temp.ar[i] = this->ar[i] + a.ar[i];
    }
    return temp;
}

Matrix& Matrix::operator+=(Matrix a) {
    for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
        this->ar[i] += a.ar[i];
    }
    return *this;
}

void Matrix::operator>>(int a[]) {
    for (int i = 0; i < sizeof(this->ar) / sizeof(int); i++) {
        a[i] = this->ar[i];
    }
}

Matrix& Matrix::operator<<(int a[]) {
    for (int i = 0; i < sizeof(this->ar) / sizeof(int); i++) {
        this->ar[i] = a[i];
    }
    return *this;
}

void Matrix::show(string name) {
    cout << name << " = { ";
    for (int result : ar) {
        cout << result << " ";
    }
    cout << "}" << endl;
}

int main()
{
    Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
    c = a + b;
    a.show("a");
    b.show("b");
    c.show("c");

    a += b;
    a.show("a");

    int x[4], y[4] = {5, 6, 7, 8};
    a >> x; // a의 각 원소를 배열 x에 복사. 
    b << y; // 배열 y의 원소 값을 b의 각 원소에 설정

    cout << "x = { ";
    for (int i = 0; i < 4; i++)
        cout << x[i] << ' '; // x[] 출력
    cout << "}" << endl;
    b.show("b");
}

// 8. Circle 클래스에 대하여 다음과 같은 연산이 가능하도록 연산자 함수를 멤버 함수로 구현하고 프로그램을 완성하세요.

#include <iostream>
#include <string>

using namespace std;

class Circle
{
    int radius;

public:
    Circle(int radius = 0);
    Circle& operator++();
    Circle operator++(int x);
    Circle operator+(int a);
    void show(string name);
};

Circle::Circle(int radius)
{
    this->radius = radius;
}

Circle& Circle::operator++()
{
    this->radius++;
    return *this;
}

Circle Circle::operator++(int x)
{
    Circle temp = *this;
    this->radius++;
    return temp;
}

Circle Circle::operator+(int a)
{
    Circle temp;
    temp.radius = this->radius + a;
    return temp;
}

void Circle::show(string name)
{
    cout << name << ") radius=" << radius << endl;
}

int main()
{
    Circle a(5), b(4);
    a.show("a");
    b.show("b");

    ++a;     // 반지름을 1 증가 시킨다. 
    a.show("a");

    b = a++; // 반지름을 1 증가 시킨다. 
    a.show("a");
    b.show("b");
    
    b = a + 3; // b의 반지름을 a의 반지름에 3을 더한 것으로 변경
    b.show("b");
}

// 9. [ ]연산자를 멤버 함수로 정의하여 제시된 결과처럼 실행하는 프로그램을 작성하세요.

#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Array
{
    double *ptr = nullptr;
    int size;

public:
    Array(int size);
    Array(const Array& a);
    ~Array();
    double& operator[](int a);
    Array& operator=(const Array& a);
    void show(string name);
    friend void swap_array(Array& a, Array& b);
};

Array::Array(int s) : size(s), ptr{new double[s]} {}

Array::Array(const Array& a) {
    if (this->ptr != nullptr) {
        delete []ptr;
        ptr = nullptr;
    }
    this->ptr = new double[a.size];
    for (int i = 0; i < a.size; i++) {
        this->ptr[i] = a.ptr[i];
    }
    this->size = a.size;
}

Array::~Array() {
    delete []ptr;
}

double& Array::operator[](int a) {
    if (a >= size || a < 0) {
        cout << "인덱스 범위 초과 오류" << endl;
        exit(0);
    }
    return this->ptr[a];
}

Array& Array::operator=(const Array& a) {
    if (this == &a) {
        return *this;
    }
    
    Array temp(a);
    swap_array(*this, temp);
    return *this;
}

void swap_array(Array& a, Array& b) {
    swap(a.ptr, b.ptr);
    swap(a.size, b.size);
}

void Array::show(string name) {
    cout << name << " = { ";
    for (int i = 0; i < this->size; i++) {
        cout << this->ptr[i] << " ";
    }
    cout << "}" << endl;
}

int main()
{
    int size;
    cout << "array size ? ";
    cin >> size;

    Array arr(size), brr(size);

    for (int i = 0; i < size; i++)
    {
        cout << i << ") input>> ";
        cin >> arr[i];
    }
    arr.show("arr");

    brr = arr;
    brr.show("brr");

    brr[2] = 34.5;
    brr[4] = 56.3;
    arr.show("arr");
    brr.show("brr");

    return 0;
}


// 10. 정수 배열을 항상 증가 순으로 유지하는 StoredArray 클래스를 작성하려고 합니다. 아래의 main()함수가 동작할 수 있도록 SortedArray 클래스를 작성하고 +와 =연산자도 작성하세요.

#include <iostream>
#include <string>

using namespace std;

class SortedArray
{
    int size;    //현재 배열의 크기
    int *p;      //정수 배열에 대한 포인터
    void sort(); //정수 배열을 오름차순으로 정렬
public:
    SortedArray();                    // p는 nullptr로 size는 0으로 초기화
    SortedArray(SortedArray &arr);    //복사 생성자
    SortedArray(int arr[], int size); //생성자. 정수 배열과 크기를 전달받아 p에 저장 후 sort() 호출
    ~SortedArray();                   //소멸자
    SortedArray operator+(SortedArray &b);
    SortedArray &operator=(const SortedArray &b); //현재 배열에 b 배열을 복사
    void show(string name);                       //배열의 원소 출력
};

SortedArray::SortedArray()
{
    this->p = nullptr;
    this->size = 0;
}

SortedArray::SortedArray(SortedArray &arr)
{
    this->p = new int[arr.size];
    for (int i = 0; i < arr.size; i++) {
        this->p[i] = arr.p[i];
    }
    this->size = arr.size;
}

SortedArray::SortedArray(int arr[], int size)
{
    this->p = arr;
    this->size = size;
    sort();
}

SortedArray::~SortedArray() {
    delete []p;
}

SortedArray SortedArray::operator+(SortedArray &b)
{
    int *arr = new int[this->size + b.size];
    for (int i = 0; i < this->size + b.size; i++) {
        if (i < this->size) {
            arr[i] = this->p[i];
        } else {
            arr[i] = b.p[i - this->size];
        }
    }
    SortedArray result(arr, this->size + b.size);
    return result;
}

SortedArray& SortedArray::operator=(const SortedArray &b)
{
    delete this->p;
    this->p = new int[b.size];
    for (int i = 0; i < b.size; i++) {
        this->p[i] = b.p[i];
    }
    this->size = b.size;
    return *this;
}

void SortedArray::sort()
{ //오름차순 버블 정렬
    if (p == nullptr || size == 0)
        return;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i; j < size - 1; j++)
        {
            if (p[j] > p[j + 1])
            {
                int temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void SortedArray::show(string name) {
    cout << name << " = { ";
    for (int i = 0; i < this->size; i++) {
        cout << this->p[i] << " ";
    }
    cout << "}" << endl;
}

int main()
{
    int n[] = {2, 20, 6};
    int m[] = {10, 7, 8, 30};
    
    SortedArray a(n, 3), b(m, 4), c;
    
    c = a + b;
    
    a.show("a");
    b.show("b");
    c.show("c");
}