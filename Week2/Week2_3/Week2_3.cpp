#include <iostream>
#include <initializer_list>

using namespace std;

//initializer_list로 받은 값은 상수, <>안에 반드시 자료형 명시
void list_exam(initializer_list<int> value) {
    int hap = 0;
    for (auto data : value) {
        hap += data;
    }
    cout << "결과 : " << hap << endl;
    cout << "평균 : " << hap / value.size() << endl;
}

int main() {
    list_exam({ 3, 12, 6, 37, 8, 43 });
    list_exam({ 5, 8, 21, 84, 12, 31, 27, 7 });
    for (auto v : { 34, 56, 87, 43, 68})
        cout << v << " ";
    return 0;
}