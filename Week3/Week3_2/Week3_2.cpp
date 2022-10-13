#include <iostream>
#include <string> // string 클래스를 사용하기 위한 헤더 파일

using namespace std; // std안에 string 정의, 이름영역지정 반드시 필요

int main() {
    string song("Falling in love with you"); // 문자열 song 또는 string song = "Falling in love with you";
    string elvis("Elvis Presley"); // 문자열 elvis
    string singer; // 문자열 singer

    cout << song + "를 부른 가수는"; // +로 문자열 연결
    cout << "(힌트 : 첫 글자는 " << elvis[0] << ") ?"; // [] 연산자 사용

    getline(cin, singer); // 문자열 입력

    if (singer == elvis) { // 문자열 비교
        cout << "맞았습니다."; 
    } else {
        cout << "틀렸습니다." + elvis + "입니다." << endl; // +로 문자열 연결
    }
}