#include <iostream>
using namespace std;
int main() {
    int width;
    cout << "높이와 너비를 입력하세요>>";

    int height; // C++에서는 변수 선언 위치에 제한 x
    
    cin >> height >> width; 

    int area = height * width;
    cout << "면적은 " << area << "\n";
}