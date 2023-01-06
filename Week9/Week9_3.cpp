#include <iostream>

using namespace std;

class Point
{
public:
    int x, y;
    void write_xy() { cout << "x=" << x << ", y=" << y << " ]" << endl; }
    Point() { Point(1, 1); };
    Point(int x, int y) : x{x}, y{y} { cout << "생성자 실행" << endl; };
    ~Point() { cout << x << " " << y << "소멸자 실행 " << endl; };
};
Point &sum(const Point &p1, const Point &p2)
{
    Point *p = new Point;
    p->x = p1.x + p2.x;
    p->y = p1.y + p2.y;
    return *p;
}
int main()
{
    Point *p1 = new Point{4, 5};
    Point *p2 = new Point{14, 15};
    Point &p3 = sum(*p1, *p2);
    cout << "p1 = [ ";
    p1->write_xy();
    cout << "p2 = [ ";
    p2->write_xy();
    cout << "p3 = [ ";
    p3.write_xy();
}
