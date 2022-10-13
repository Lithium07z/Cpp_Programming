#include <iostream>

using namespace std;

class Circle { // Circle 선언 - 클래스 정의
public:
    int radius; // 멤버 변수 선언
    double getArea(); // 멤버 함수 선언
};

double Circle::getArea() {
    return 3.14 * radius * radius;
}

int main() {
    Circle donut;
    donut.radius = 1;
    double area = donut.getArea();
    cout << "donut 면적은 " << area << endl;

    Circle pizza;
    pizza.radius = 30;
    area = pizza.getArea();
    cout << "pizza의 면적은 " << area << endl;
} 