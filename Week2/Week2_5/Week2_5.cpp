#include <iostream>
#include <string>

using namespace std;
struct Entry {
    string name;
    int value;
};
Entry read_entry() {
    string s;
    int i;
    cout << "in_string in_int : ";
    cin >> s >> i;
    return { s, i };
}
int main() {
    auto e = read_entry();
    cout << e.name << e.value << endl;

    auto [n, v] = read_entry(); // 구조화된 바인딩 : 데이터 멤버에 사용 단, 접근 지정자 public
                                // tuple 분리, map 사용 시 유용함

    cout << n << v << endl;
}