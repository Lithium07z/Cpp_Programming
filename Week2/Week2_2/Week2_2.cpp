#include <iostream>

auto IsMaxLevel(int i) {
    if (i >= 100) {
        return true;
    } else {
        return false;
    }
}

int main() {
    auto result = IsMaxLevel(50); // 일반 함수의 반환 값 타입으로 사용 가능
    auto lambda = [](int a, int b) {return a + b; }; // 람다 표현식에서 사용
    using namespace std;
    
    cout << std::boolalpha << result << endl;
    cout << "result :" << lambda(11, 22) << endl;

    return 0;
}