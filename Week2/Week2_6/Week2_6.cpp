#include <iostream>
#include <string>
#include <tuple> // tuple Ŭ����

using namespace std;

int main() {
    tuple t{"binding", 23, 45.23}; // C++ 17���� �����ڿ��� �ۺ� �μ� �߷� ��� �߰�
                                   // g++ Week2_6.cpp -std=c++17 -o Week2_6 > .\Week2_6���� �����ؾ� �� 
    auto[str, i, d] = t; // ����ȭ�� ���ε� : tuple �и�

    cout << "str : " << str << endl;
    cout << "i : " << i << endl;
    cout << "d : " << d << endl;

    return 0; 
}