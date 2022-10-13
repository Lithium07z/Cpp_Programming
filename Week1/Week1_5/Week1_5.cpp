#include <iostream>
using namespace std;

int main() {
    // 엄격한 타입 적용, 자동으로 열거형 값이 정수로 변환되지 않음
    // 열거 타입 값을 사용할 때 반드시 범위지정연산자(::)를 붙여야 함
    enum Menu {Insert = 1, Delete, Update}; // C에서 쓰는 방법
    enum class Color {Blue = 1, Green, Red, Black}; // C++에서 쓰는 방법, 클래스로 만듬

    Menu choice = Insert;
    Color color = Color::Blue; // 열거 타입 값을 사용할 때 반드시 범위지정연산자(::) 사용해야 함

    if (choice == 1) // 열거 타입 값이 자동으로 정수타입으로 변환
        cout << "Insert" << endl; // choice == Insert가 아니어도 자동으로 앎

    if (static_cast<int>(color) == 1) // 정수 타입으로 사용하려면 명시적 형 변환
        cout << "Blue" << endl;
}