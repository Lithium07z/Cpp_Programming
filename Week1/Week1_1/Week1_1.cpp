#include <iostream> // ��� ���Ͽ� Ȯ���ڸ� ������ ����
int main() {
    //std::cout << "Hello"<<std::endl; // std -> namespace, endl -> ������, �ٹٲ�
    //std::cout << "ù ��° �������Դϴ�.\n";

    //using namespace std; // std �̸� ������ ����� ��� �̸��� std:: ����
    //cout<< "Hello"<<endl; // std:: ����
    
    using std::cout; // cout�� ���ؼ��� std:: ����
    cout<< "Hello" << std::endl; // cout�� ���ؼ��� �����߱� ������ endl�� std::�� �ٿ�����
    std:cout << "Hello\n" << "World"; // << ������ ���� ��밡��
    return 0; // main() �Լ������� ����
}