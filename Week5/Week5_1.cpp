#include <iostream>

using namespace std;

class Circle
{
    int radius;

public:
    Circle() = default;

    Circle(int r) :  radius(r) { }

    void setRadius(int r) { radius = r;}
    int getRadius() { return radius; }
    double getArea();
};

double Circle::getArea() {
    return 3.14 * radius * radius;
}

int main() {
    Circle cirarr[2]; // Circle 객체 배열 생성, 디폴트 생성자 없으면 오류
    
    for (int i = 0; i < 2; i++) { // 배열의 각 원소인 객체의 멤버 접근
        cout << "Circle " << i << "의 radius = " << cirarr[i].getArea() << endl;
    }

    cirarr[0].setRadius(10); // 배열의 각 원소인 객체의 멤버 접근
    cirarr[1].setRadius(20);

    for (int i = 0; i < 2; i++) {
        cout << "Circle " << i << "의 면적 = " << cirarr[i].getArea() << endl;
    }

    for (auto obj : cirarr) { // auto & 범위 기반 for
        cout << "Circle 면적 = >> " << obj.getArea() << endl;
    }

    Circle *p;
    p = cirarr;
    for (int i = 0; i < 2; i++) { // 객체 포인터로 배열 접근
        cout << "Circle " << i << "의 면적 = " << p -> getArea() << endl;
        p++;
    }
}