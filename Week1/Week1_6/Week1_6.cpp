#include <iostream>
using namespace std;

void method(const int* i) {
    int *d = const_cast<int*>(i); // 매개변수 변수 i의 const 속성 해제
    cout << *d;
}

int main() {
    double d = 34.5;
    int i = (int)d; // C에서 캐스팅하는 법
    int si = static_cast<int>(d); // C++에서 캐스팅하는 법

    int digit = 34;
    double* dp = (double*)&digit; // 컴파일 성공 / 단, 위험한 코딩임 정수는 4byte인데 실수형 포인터는 8byte로 다른 위치를 가리킬 수 있음
    //double* sdp = static_cast<double*>(&digit); // 컴파일 오류 / 명시적 변환시는 컴파일 오류 발생
    method(&si);
}