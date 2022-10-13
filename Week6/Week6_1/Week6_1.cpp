#include <iostream>
#include <memory>

using namespace std;

int main()
{
    unique_ptr<int> p(new int); // unique_ptr 사용법1
    *p = 99;                    //포인터의 초기화
    cout << "*p = " << *p << endl;

    unique_ptr<int> ap = move(p); // unique_ptr<int> ip = p; //error, move()를 사용해 포인터 이동
    cout << "*ap = " << *ap << endl; // cout << "*p = " << *p << endl; //실행시간 오류

    unique_ptr<double> sp = make_unique<double>(23.5); // unique_ptr 사용법2
    cout << "*sp = " << *sp << endl;

    auto asp = make_unique<int[]>(5); // unique_ptr 사용법3, make_unique<T>() 사용을 권고
    for (int i = 0; i < 5; i++) {
        asp[i] = 10 + i;
        cout << asp[i] << " ";
    }
    cout << endl;
}