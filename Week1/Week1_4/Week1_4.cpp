#include <iostream>
#include <iomanip> // 조작자 사용을 위해 필요
using namespace std;
int main() {
    int data;
    bool flag;
    cout << "여러 진법으로 정수 입력 받기" << endl;
    cout << "10진법으로 입력하기 : ";
    cin >> data; cout << "10진법 : " << data << endl;

    cout << "8진법으로 입출력하기 : ";
    cin >> oct >> data; cout << "8진법 : " << oct << data << endl; // 출력 때는 oct 빼야할 듯

    cout << "16진법으로 입출력하기 : ";
    cin >> hex >> data; cout << "16진법 : " << hex << data << endl; // 출력 때는 hex 빼야할 듯

    cout << "불 자료형으로 입출력하기 : ";
    cin >> boolalpha >> flag; cout << "불 리터럴 출력 : " << boolalpha << flag << endl;

    cout << "고정 소수점 출력하기 : " << fixed << setprecision(2) << 2345.12432 << endl;
    return 0;
}