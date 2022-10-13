// 2. �� ��ȣ�� ä�� ��������. 
// A. C++�� ( )������ ȣȯ���� ( ) ���� �߰��� ��ǥ�� ����Ǿ���.
// Q. C++�� (C)������ ȣȯ���� (��ü����) ���� �߰��� ��ǥ�� ����Ǿ���.

// B. C++ ���α׷��� Ȯ���ڴ� ( ) �̴�.
// Q. C++ ���α׷��� Ȯ���ڴ� (cpp) �̴�.

// C. ( )��� ������ ǥ�� ������� ���� Ŭ������ ��ü, ���� ���� ����Ǿ� �ִ�.
// Q. (iostream)��� ������ ǥ�� ������� ���� Ŭ������ ��ü, ���� ���� ����Ǿ� �ִ�.

// D. �̸� ������ �����Ϸ��� ( )���þ ����Ѵ�. 
// Q. �̸� ������ �����Ϸ��� (using)���þ ����Ѵ�.

// E. ǥ�� �Է� ��ġ�� Ű����� �����͸� �Է� ���� �� ( ) ��ü�� ����Ѵ�.
// Q. ǥ�� �Է� ��ġ�� Ű����� �����͸� �Է� ���� �� (cin) ��ü�� ����Ѵ�.

// F. bool Ÿ������ ����� ������ ����� ���� �� ���ͷ��� ����Ϸ��� ������ ( )�� ����ؾ� �Ѵ�.
// Q. bool Ÿ������ ����� ������ ����� ���� �� ���ͷ��� ����Ϸ��� ������ (boolalpha)�� ����ؾ� �Ѵ�.

// G. const int *ptr = &val;�� �ǹ̴� ( )�� �̿��ؼ� ( )�� ���� ������ �� ������ �ǹ��Ѵ�.
// Q. const int *ptr = &val;�� �ǹ̴� (������)�� �̿��ؼ� (val)�� ���� ������ �� ������ �ǹ��Ѵ�.

// H. uniform initialization�� ( )�� ����Ͽ� ����, �迭, ��ü ���� �ʱ�ȭ �Ѵ�.
// Q. uniform initialization�� ({}, �߰�ȣ)�� ����Ͽ� ����, �迭, ��ü ���� �ʱ�ȭ �Ѵ�.

// 8. ���� �� ������ ������ �߻��ϴ� ������ �����ΰ���?
// int d {3. 6};
// int f = 3.6;

// ����
// int d {3.6}; 
// �Ǽ��� ���������� ��Һ�ȯ �Ұ��� 

// 9. ���� ���α׷��� cpp�� ������ �ҽ��� ����� �Բ� �����ϼ���. auto������ ��ȯ ������ ���� ��� �����ϼ���.
//#include <stdio.h>
//  int sum(int s, int e); // �Լ� ���� ����
//  int sum(int s, int e) {
//  int tmp, res = 0;
//   
//  if(s>e) {
//      tmp = e;
//      e = s;
//      s = tmp;
//  }
//  for (int k = s; k <= e; k++) {
//      res += k;
//  }
//      return res;
//}
//
//  int main() {
//      int a, b;
//      printf("ù ���� ������ ���� �Է��ϼ��� : ");
//      scanf("%d %d", &a, &b);
//      printf("%d���� %d������ ���� %d �Դϴ�\n", a, b, sum(a, b));
//      return 0;
//  }

// ����
#include <iostream>

using namespace std;

auto sum(int s, int e); // �Լ� ���� ����

auto sum(int s, int e) {
    auto tmp = 0;
    auto res = 0;

    if (s > e) {
        tmp = e;
        e = s;
        s = tmp;
    }
    for (auto k = s; k <= e; k++) {
        res += k;
    }
    return res;
}

int main()
{
    auto a = 0;
    auto b = 0;
    cout << "ù ���� ������ ���� �Է��ϼ��� : ";
    cin >> a >> b;
    cout << a << "���� " << b << "������ ���� " << sum(a, b) << " �Դϴ�." << endl;
    return 0;
}

// 13. �Էµ� �Ǽ����� ���� �κа� �Ҽ��� �Ʒ��κ��� �и��ؼ� ����ϴ� ���α׷��� ����ȭ���� �����Ͽ� �ۼ��ϼ���. (Hint: static_cast)
// ����
#include <iostream>

using namespace std;

int main() {
    double value = 0;

    cout << "�Ǽ��� �Է��ϼ��� : ";
    cin >> value; 

    cout << "���� part : " << static_cast<int>(value) << endl;
    cout << "�Ҽ� part : " << value - static_cast<int>(value);

    return 0;
}

// 14. ���õ� main() �Լ��� ���� ����� �����Ͽ� �� ��° �μ��� ���� ����� �Ÿ��� �ִ� ���ڸ� ����ϴ� ���α׷��� �ϼ��ϼ���. (Hint: initializer_list)
// ����
#include <iostream>
#include <initializer_list>

using namespace std;

char list_exam(initializer_list<int> value, int word) { 
    int min = 1000000;
    int result = 0;

    for (int temp : value) {
        int sub = abs(temp - word);
        if (min > sub) {
            min = sub;
            result = temp;
        }
    }
    return result;
}

int main() {
    cout << "{ 'd', 'p', 'r', 'w', 'g', 'f' }���� �� h�� ����� ���ڴ� : " ;
    cout << list_exam({ 'd', 'p', 'r', 'w', 'g', 'f' }, 'h') << endl;
    cout << "{ 'k', 'q', 'b', 'r', 'a', 'e', 'v', 'z'}���� �� w�� ����� ���ڴ� : ";
    cout << list_exam({ 'k', 'q', 'b', 'r', 'a', 'e', 'v', 'z'}, 'w') << endl;
}

// 15. ����ڿ��� ������ �Է¹޾� �迭�� ������ �� �迭�� ������ ������������ �����ϴ� ���α׷��� ����ȭ���� �����Ͽ� �ۼ��ϼ���. (Hint: sort(array.begin(), array.end()))
// ����
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main() {
    cout << "���� �Է� : ";

    array<int, 5> arr;
    for (auto i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }

    cout << "�迭�� ����� ���� : ";
    for (auto i = 0; i < arr.size(); i++) {
        cout << arr.at(i) << " ";
    }
    cout << endl << "�迭 �������� ���� : ";

    sort(arr.begin(), arr.end());
    for (auto temp : arr) {
        cout << temp << " ";
    }
    return 0;
}