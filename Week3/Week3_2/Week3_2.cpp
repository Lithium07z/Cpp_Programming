#include <iostream>
#include <string> // string Ŭ������ ����ϱ� ���� ��� ����

using namespace std; // std�ȿ� string ����, �̸��������� �ݵ�� �ʿ�

int main() {
    string song("Falling in love with you"); // ���ڿ� song �Ǵ� string song = "Falling in love with you";
    string elvis("Elvis Presley"); // ���ڿ� elvis
    string singer; // ���ڿ� singer

    cout << song + "�� �θ� ������"; // +�� ���ڿ� ����
    cout << "(��Ʈ : ù ���ڴ� " << elvis[0] << ") ?"; // [] ������ ���

    getline(cin, singer); // ���ڿ� �Է�

    if (singer == elvis) { // ���ڿ� ��
        cout << "�¾ҽ��ϴ�."; 
    } else {
        cout << "Ʋ�Ƚ��ϴ�." + elvis + "�Դϴ�." << endl; // +�� ���ڿ� ����
    }
}