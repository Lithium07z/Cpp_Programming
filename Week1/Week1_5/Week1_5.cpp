#include <iostream>
using namespace std;

int main() {
    // ������ Ÿ�� ����, �ڵ����� ������ ���� ������ ��ȯ���� ����
    // ���� Ÿ�� ���� ����� �� �ݵ�� ��������������(::)�� �ٿ��� ��
    enum Menu {Insert = 1, Delete, Update}; // C���� ���� ���
    enum class Color {Blue = 1, Green, Red, Black}; // C++���� ���� ���, Ŭ������ ����

    Menu choice = Insert;
    Color color = Color::Blue; // ���� Ÿ�� ���� ����� �� �ݵ�� ��������������(::) ����ؾ� ��

    if (choice == 1) // ���� Ÿ�� ���� �ڵ����� ����Ÿ������ ��ȯ
        cout << "Insert" << endl; // choice == Insert�� �ƴϾ �ڵ����� ��

    if (static_cast<int>(color) == 1) // ���� Ÿ������ ����Ϸ��� ����� �� ��ȯ
        cout << "Blue" << endl;
}