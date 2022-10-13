#include <iostream> // 헤더 파일에 확장자를 붙이지 않음
int main() {
    //std::cout << "Hello"<<std::endl; // std -> namespace, endl -> 조작자, 줄바꿈
    //std::cout << "첫 번째 맛보기입니다.\n";

    //using namespace std; // std 이름 공간에 선언된 모든 이름에 std:: 생략
    //cout<< "Hello"<<endl; // std:: 생략
    
    using std::cout; // cout에 대해서만 std:: 생략
    cout<< "Hello" << std::endl; // cout에 대해서만 생략했기 때문에 endl은 std::를 붙여야함
    std:cout << "Hello\n" << "World"; // << 연산자 연속 사용가능
    return 0; // main() 함수에서만 생략
}