#include <iostream>

auto IsMaxLevel(int i) {
    if (i >= 100) {
        return true;
    } else {
        return false;
    }
}

int main() {
    auto result = IsMaxLevel(50); // �Ϲ� �Լ��� ��ȯ �� Ÿ������ ��� ����
    auto lambda = [](int a, int b) {return a + b; }; // ���� ǥ���Ŀ��� ���
    using namespace std;
    
    cout << std::boolalpha << result << endl;
    cout << "result :" << lambda(11, 22) << endl;

    return 0;
}