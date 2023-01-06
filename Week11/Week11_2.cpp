#include <iostream> // 프렌드 선언 – 다른 클래스의 멤버 함수

using namespace std;

class Rect;

class RectManager
{ // RectManager 클래스 선언
public:
    bool equals(Rect r, Rect s);
};

class Rect
{ // Rect 클래스 선언
    int width, height;

public:
    Rect(int width, int height)
    {
        this->width = width;
        this->height = height;
    }
    friend bool RectManager::equals(Rect r, Rect s); // RectManager 클래스의 equals() 멤버를 프렌드로 선언
};

bool RectManager::equals(Rect r, Rect s)
{
    if (r.width == s.width && r.height == s.height)
        return true;
    else
        return false;
}

int main()
{
    Rect a(3, 4), b(3, 4);
    RectManager man;
    if (man.equals(a, b))
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;
}