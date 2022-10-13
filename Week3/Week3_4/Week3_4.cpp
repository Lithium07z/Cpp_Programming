#include <iostream>
#include <string>
#include <locale> // 문자를 다루는 함수, isdigit(), toupper(), isalpha(), islower()

using namespace std;

int main() {
    string s1 = "C++ programming";

    cout << "문자열 검색 : " << s1.find("p") << endl; // 문자나 문자열 검색, 없으면 -1반환
    cout << "문자열 추출 : " << s1.substr(2,4) << endl; // 문자열 일부 추출, 인덱스 2에서 4개의 문자 반환
    cout << "문자열 추출 : " << s1.substr(2) << endl; // 문자열 일부 추출, 인덱스 2에서 끝까지 반환
    cout << "문자열의 각 문자 다루기 : " << s1.at(5) << endl; // 인덱스 5에 있는 문자 반환
    cout << "문자 다루기 : " << static_cast<char>(toupper('a')) << endl;
    
    if (isdigit(s1.at(6))) {
        cout << "숫자" << endl;
    } else if (isalpha(s1.at(6))) { 
        cout << "문자" << endl;
    } else {
        cout<<"해당없음"<<endl;
    }
    return 0;
}