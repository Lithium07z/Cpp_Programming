#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1 = "C++ programming", s2  = "language";
    cout << "문자열 비교 : " << s1.compare(s2) << endl;
    cout << "문자열 연결 : " << s1.append(s2) << endl;

    s1 = "C++ programming";

    cout << "문자열 삽입 : " << s1.insert(3, "really") << endl;
    cout << "문자열 대치 : " << s1.replace(3, 6, "study") << endl; // 3부터 6개의 문자를 study로 대치
    cout << "문자열 길이 : " << s1.length() << endl;
    cout << "문자열 길이 : " << s1.size() << endl;
    cout << "문자열 삭제 : " << s1.erase(0, 4) << endl; // 문자열 일부분 삭제 0부터 4개 문자 삭제

    s2 = s1; // 문자열 복사, 깊은 복사
    s1.clear(); // 문자열 전체 삭제
    cout << "문자열 삭제 s1 : " << s1 << endl;
    cout << "문자열 복사 후 s2 : " << s2 << endl;
    return 0;
}