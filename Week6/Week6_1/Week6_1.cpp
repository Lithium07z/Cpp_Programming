#include <iostream>
#include <memory>

using namespace std;

int main()
{
    unique_ptr<int> p(new int); // unique_ptr ����1
    *p = 99;                    //�������� �ʱ�ȭ
    cout << "*p = " << *p << endl;

    unique_ptr<int> ap = move(p); // unique_ptr<int> ip = p; //error, move()�� ����� ������ �̵�
    cout << "*ap = " << *ap << endl; // cout << "*p = " << *p << endl; //����ð� ����

    unique_ptr<double> sp = make_unique<double>(23.5); // unique_ptr ����2
    cout << "*sp = " << *sp << endl;

    auto asp = make_unique<int[]>(5); // unique_ptr ����3, make_unique<T>() ����� �ǰ�
    for (int i = 0; i < 5; i++) {
        asp[i] = 10 + i;
        cout << asp[i] << " ";
    }
    cout << endl;
}