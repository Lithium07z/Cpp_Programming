// 3. ������ ���ϼ���
// A. C++ ǥ�� ���̺귯�� �׷� 3���� �����ϼ���.
// Q. C ���̺귯��, C++ ����� ���̺귯��, C++ STL ���̺귯��

// B. C++ ���α׷��� ������ �����ϴ� �Լ� ������ �����Ͻÿ�.
// Q. int main(void)

// C. C++ ǥ�ؿ��� cin, cout ��ü�� � ��� ���Ͽ� ����Ǿ� �ֳ���?
// Q. <iostream>

// D. C++ ǥ�� ���̺귯���� ��� ����� �̸� ������ �����ΰ���?
// Q. std::

// E. �̸������� ������ �� ����ϴ� Ű����� �����ΰ���?
// Q. namespace

// F. namespace hallym�� ���ǵ� �Լ� software()�� ȣ���ϴ� ������ ������. ��, software() �Լ��� ��ȯ ���� �Ű������� ������ �ʽ��ϴ�.
// Q. hallym::software

// G. ���� ���忡 ������ �߻����� �ʵ��� �����ϼ���. using ���þ�� ������� �ʽ��ϴ�.
// Q. std::cout <<  "C++";

// H. ������ �� ������ �ʱ�ȭ �� ������ ���� �����ϴ� �ڷ����� �����ΰ�?
// Q. auto

// 4. ���� ���� �߿��� Ʋ�� �κ��� �ùٸ��� �����ϼ���.
// #include <iostream.h> 
// using std namespace; 
// cin << data; 
// 100 >> cout;

// ���� 
#include <iostream>

using namespace std;

cin >> data;
cout << 100;

// 5. main()���� �̸� ������ �����ϴ� ������ ������� �������� �մϴ�. �Ʒ��� �ڵ带 �����ϼ���.
// #include <iostream>
// #include <string>
// int main() {
// string name; 
// cout << "�̸��� �Է��ϼ��� : "; 
// cin >> name; 
// cout << "name : " << name << endl; 
// return 0;
// }

// ����
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "�̸��� �Է��ϼ��� : ";
    std::cin >> name;
    std::cout << "name : " << name << std::endl;
    return 0;
}

// 6. ���õ� ���α׷��� ���Ͽ� ������ ���ϼ���.
// #include <iostream>
// #include <string>
// using namespace std;
// int main() {
// string name;
// cout << "�̸��� �Է��ϼ��� : ";
// cin >> name;
// cout << name << " �� ȯ���մϴ� "<<endl;
// return 0;
// }

// A. ������ ���� Ű����� ��C++���� �Է��Ͽ��� �� ����� �����ϼ���.
// Q. C++ �� ȯ���մϴ�

// B. ������ ���� Ű����� ��C++ OOP���� �Է��Ͽ��� �� ����� �����ϼ���.
// Q. C++ �� ȯ���մϴ�

// 7. ������ ������ �߻����� �ʵ��� ��ĭ�� ä�� ��������.
// #include <iostream>
// _______________
// _______________
// int main() {
// int count;
// cout << "�ݺ� Ƚ���� �Է��ϼ��� : ";
// std::cin >> count;
// cout << count << " ȸ �ݺ��մϴ�. "<<endl;
// return 0;
// }

// ����
#include <iostream>

using std::cout;
using std::endl;
 
int main() {
int count;
cout << "�ݺ� Ƚ���� �Է��ϼ��� : ";
std::cin >> count;
cout << count << " ȸ �ݺ��մϴ�. "<< endl;
return 0;
}