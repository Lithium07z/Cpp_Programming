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
    Circle getCircle();
    Circle(const Circle& c);
};

Circle getCircle() {
    Circle temp(10);
    return temp;
}

Circle::Circle() : Circle(1) {}

Circle::Circle(int radius)
{
    this->radius = radius;
    cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(const Circle& c) {
    cout << "복사 생성자 실행 radius = " << radius << endl;
    
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
    //Circle c1(5);
    Circle c2(30);
    Circle c1 = c2; // 객체 치환 c1, c2는 독립적인 공간에 같은 값을 보유함
    Circle c3 = getCircle();
    cout << c3.getRadius() << endl;
}