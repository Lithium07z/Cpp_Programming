#include <iostream>
using namespace std;

void method(const int* i) {
    int *d = const_cast<int*>(i); // �Ű����� ���� i�� const �Ӽ� ����
    cout << *d;
}

int main() {
    double d = 34.5;
    int i = (int)d; // C���� ĳ�����ϴ� ��
    int si = static_cast<int>(d); // C++���� ĳ�����ϴ� ��

    int digit = 34;
    double* dp = (double*)&digit; // ������ ���� / ��, ������ �ڵ��� ������ 4byte�ε� �Ǽ��� �����ʹ� 8byte�� �ٸ� ��ġ�� ����ų �� ����
    //double* sdp = static_cast<double*>(&digit); // ������ ���� / ����� ��ȯ�ô� ������ ���� �߻�
    method(&si);
}