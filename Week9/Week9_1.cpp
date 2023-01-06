#include<iostream> // call by value 예시

using namespace std;

class Circle
{
private:
    int radius;

public:
    Circle();
    Circle(int r);
    ~Circle();
    double getArea() { return 3.14 * radius * radius; }
    int getRadius() { return radius; }
    void setRadius(int radius) { this->radius = radius; }
};
Circle::Circle() : Circle(1) {}
Circle::Circle(int radius)
{
    this->radius = radius;
    cout << "생성자 실행 radius = " << radius << endl;
}
Circle::~Circle()
{
    cout << "소멸자 실행 radius = " << radius << endl;
}

void increase(Circle c)
{
    int r = c.getRadius();
    c.setRadius(r + 1);
}
int main()
{
    Circle waffle(30); // 생성자 실행
    increase(waffle); // 값에 의한 호출 때문에 생성자 호출 x, increase에서 call by value 때문에 만들어진 c 소멸
    cout << waffle.getRadius() << endl; // 30 출력됨, increase는 call by value이므로 waffle의 값은 변경 X
    // waffle 소멸
}