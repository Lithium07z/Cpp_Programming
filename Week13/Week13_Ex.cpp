// 2. C++ 상속의 종류에 대해 설명하고 예를 제시하세요.
// public 상속 : 기본 클래스의 protected, public 멤버 속성을 그대로 계승
// protected 상속 : 기본 클래스의 protected, public 멤버 속성을 protexcted로 계승
// private 상속 : 기본 클래스의 protected, public 멤버 속성을 private로 계승

// 3. 다중 상속의 문제점과 해결방법의 예를 제시하고 설명하세요. 
// BaseIO라는 클래스를 In과 Out이라는 두 클래스가 모두 상속받고 있고 InOut이라는 클래스가
// In과 Out을 모두 다중 상속하고 있다면 In이 상속받은 BaseIO의 변수와 Out이 상속받은 BaseIO의 변수를
// 구별하지 못해 모호성 문제가 발생한다. 

// 4. 가상 상속을 선언할 때 사용하는 키워드는 무엇인가요?
// Q. virtual

// 5. 클래스 Rocket과 클래스 Computer를 동시에 상속받는 클래스 Statellite를 선언하는 문장을 작성하세요.
//class Statellite : public Rocket, public Computer {};

// 6. 다음 코드를 사용해 객체 b가 생성될 때 화면에 출력되는 내용은 무엇인가요?
/*
class A {
    public:
    A() { cout << "생성자 A" << endl; }
    A(int x) { cout << "생성자 A" << x<< endl; }
};

class B: public A {
    public:
    B() { cout << "생성자 B" << endl;}
    B(int x) { cout << "생성자 B" << x << endl; }
    B(int x, int y) : A(x+y+2) {cout << "생성자 B" << x + y + 2 << endl; }
};
*/
// A. B b;
// 생성자 A
// 생성자 B
// B. B b(10);
// 생성자 A
// 생성자 B1O
// C. B b(10, 20);
// 생성자 A32
// 생성자 B32

// 7. BaseArray클래스를 상속 받아 큐로 작동하는 MyQueue 클래스를 작성하세요.
#include <iostream>
#include <string>

using namespace std;

class BaseArray
{
    int capacity; //동적 할당된 메모리의 총 용량
    int *mem;     //동적 할당된 메모리
protected:
    BaseArray(int capacity = 100)
    {
        this->capacity = capacity;
        mem = new int[capacity];
    }
    ~BaseArray() { delete[] mem; }
    void put(int index, int val) { mem[index] = val; }
    int get(int index) { return mem[index]; }
    int getCapacity() { return capacity; }
};

class MyQueue : public BaseArray
{
    int head; //데이터를 넣을 위치는 head
    int tail; //데이터 꺼내는 위치는 tail+1
    int size; //현재 큐 안에 있는 데이터의 개수
public:
    MyQueue(int capacity); // capacity만큼 BaseArray 생성, head, tail, size 초기화
    void enqueue(int n);   //큐의 head 위치에 데이터 넣기
    int dequeue();         //큐의 tail+1 위치에서 데이터를 꺼내서 리턴
    int capacity();        //큐의 총 용량 리턴
    int length();          //큐에 있는 데이터의 개수 리턴
};

MyQueue::MyQueue(int capacity) : BaseArray(capacity)
{
    this->head = 0;
    this->tail = 0;
    this->size = 0;
}

void MyQueue::enqueue(int n)
{
    if (getCapacity() <= this->size)
    {
        return;
    }
    tail = (tail + 1) % getCapacity();
    put(tail, n);
    size++;
}

int MyQueue::dequeue()
{
    if (size == 0)
    {
        return 0;
    }
    head = (head + 1) % getCapacity();
    int temp = get(head);
    put(head, 0);
    size--;
    return temp;
}

int MyQueue::capacity()
{
    return getCapacity();
}

int MyQueue::length()
{
    return size;
}

int main()
{
    int capa;
    cout << "큐의 전체 용량은? ";
    cin >> capa;
    MyQueue mq(capa);
    cout << "큐의 용량 = " << mq.capacity() << endl;

    int cnt, n, i;
    cout << "\n큐에 저장할 정수 개수는? ";
    cin >> cnt;
    for (i = 0; i < cnt; i++)
    {
        cout << " " << i << ") ";
        cin >> n;
        mq.enqueue(n); //큐에 데이터 넣기
    }

    cout << "큐의 현재 크기 = " << mq.length() << endl;

    cout << "\ndequeue = " << mq.dequeue(); //큐에서 꺼내 출력
    cout << "\ndequeue = " << mq.dequeue(); //큐에서 꺼내 출력
    cout << "\n큐의 현재 크기 = " << mq.length() << endl;

    cout << "\n큐에 저장할 정수 개수는? ";
    cin >> cnt;
    for (i = 0; i < cnt; i++)
    {
        cout << " " << i << ") ";
        cin >> n;
        mq.enqueue(n); //큐에 데이터 넣기
    }

    cout << "\n큐의 원소를 순서대로 꺼내 출력 하면...";
    while (mq.length() != 0)
    {
        cout << mq.dequeue() << ' '; //큐에서 꺼내 출력
    }
    cout << endl;
    cout << "큐의 용량 = " << mq.capacity() << endl;
    cout << "큐의 현재 크기 = " << mq.length() << endl;
}