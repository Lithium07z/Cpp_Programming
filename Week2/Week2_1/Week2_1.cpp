#include <iostream>
#include <typeinfo> // typeid 연산자 사용 > 데이터 타입 정보 반환

using namespace std;

int main() {
    auto name = "range"; // auto로 선언할 때는 반드시 초기화 해야 함
    auto value = 20;
    auto number{ 20 }; // 직접 리스트 초기화(C++17), int
    auto digit = { 20 }; // 복사 리스트 초기화(C++17), initializer_list<int>

    cout << "name : " << name << endl;
    cout << "number : " << number << endl;
    cout << "name(type) :" << typeid(name).name() << endl;
    cout << "value(type) : " << typeid(value).name() << endl;
    cout << "number(type) : " << typeid(number).name() << endl;
    cout << "digit(type) : " << typeid(digit).name() << endl;
}