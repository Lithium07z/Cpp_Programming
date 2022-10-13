#include <iostream>
#include <string>
#include <tuple> // tuple 클래스

using namespace std;

int main() {
    tuple t{"binding", 23, 45.23}; // C++ 17부터 생성자에서 템블릿 인수 추론 기능 추가
                                   // g++ Week2_6.cpp -std=c++17 -o Week2_6 > .\Week2_6으로 실행해야 함 
    auto[str, i, d] = t; // 구조화된 바인딩 : tuple 분리

    cout << "str : " << str << endl;
    cout << "i : " << i << endl;
    cout << "d : " << d << endl;

    return 0; 
}