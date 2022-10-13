#include <iostream>

int len(char* p);

using namespace std;

int main() {
    char str[50]; 
    char* p = NULL;

    cout << "문자열 입력 : ";
    cin >> str; // gets로 입력받는 값 str에 저장
    p = str; // str 시작주소 포인터p에 저장
    cout << "길이 : " << len(p); // 반환된 값 출력 

    return 0;
}

int len(char* p) {
    int count = 0;
    while (*p++) { // 문자열 끝 null이면 반복문 끝
        count++;
    }
    return count; // 갯수반환 
}