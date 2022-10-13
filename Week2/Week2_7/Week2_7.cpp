#include <iostream>
#include <array> // array 클래스
#include <algorithm> // sort() 함수

using namespace std;

int main() { // array 예시
    array<int, 5> farr{3, 6, 11, 5, 7}; // 자료형과 크기를 반드시 명시해야 함
    array<int, 6> sarr;
    sarr = {12, 4, 31, 46, 23, 9};

    cout << "farr size = " << farr.size() << endl; // size()함수 : 배열크기

    cout << "farr.at(2) = " << farr.at(2) << ", farr[2] = " << farr[2] << endl; // at()함수는 유효 범위 검사, []보다 안정적

    cout << "farr 첫번째 원소 = " << farr.front() << ", farr 마지막 원소 = " << farr.back() << endl;

    cout << "farr 배열 상태 = " << boolalpha << farr.empty() << endl; // empty() : 빈 배열 true, 원소가 있으면 false

    cout << "sarr sort = ";
    sort(sarr.begin(), sarr.end()); // 반복자와 sort()함수를 사용, 배열 원소 정렬
    for (auto value : sarr) {
        cout << value << " ";
    }
}