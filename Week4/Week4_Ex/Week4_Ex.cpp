// ���ڿ�
// 4. �Ʒ��� C ���ڿ��� Ȱ���ϴ� �ڵ带 ���� ����� �������� C++ ���ڿ��� �̿��ؼ� �ڵ带 �ۼ��ϼ���.
// const char* str = "This is a string.";
// cout << strlen(str) << endl;

#include <iostream>
#include <string>

using namespace std;

int main() {
    string str("This is a string.");
    cout << str.length() << endl;
    return 0;
}

// 5. �Ʒ��� C ���ڿ��� Ȱ���ϴ� �ڵ带 ���� ����� �������� C++ ���ڿ��� �̿��ؼ� �ڵ带 �ۼ��ϼ���. 
// char str1[40] = "The time has come.";
// const char* str2 = "Are your ready?";
// strcat (str1, str2);
// cout << str1 << endl;

#include <iostream>
#include <string>

using namespace std;

int main() {
    string str1 = "The time has come.";
    const string str2 = "Are your ready?";
    str1.append(str2);
    cout << str1 << endl;
    return 0;
}

// 6. ���� �ڵ�� C ���ڿ��� ù��° ���ڸ� �����ϴ� �ڵ��Դϴ�. ���� ����� �������� C++ ���ڿ��� Ȱ���� �ڵ带 �ۼ��ϼ���.
// const char* str = "ABCDEFGH";
// str = str + 1;
// cout << str << endl;

#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "ABCDEFGH";
    str.erase(0, 1);
    cout << str << endl;
}

// 7. �Ʒ��� C ���ڿ��� Ȱ���ϴ� �ڵ带 ���� ����� �������� C++ ���ڿ��� �̿��ؼ� �ڵ带 �ۼ��ϼ���.
// const char str[] = "This is a long string.";
// char* p = strstr (str, "is"); 
// cout << *p << endl;
// cout << p << endl;

#include <iostream>
#include <string>

using namespace std;

int main() {
    const string str = "This is a long string.";
    int index = str.find("is");
    cout << str[index] << endl;
    cout << str.substr(index) << endl;
    // cout << str.erase(0, index) << endl; �� ����
}

// 8. ������ ���� C ���ڿ��� Ȱ���ϴ� �ڵ带 ���� ����� �������� C++ ���ڿ��� �ڵ带 �ۼ��ϼ���.
// cost char* str = "ABCDEFGH";
// str = str + strlen(str) - 1;
// cout << str << endl;

#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "ABCDEFGH";
    cout << str.back() << endl;
}

// 9. �Ʒ��� ���õ� �Լ� ������ main() �Լ��� �����Ͽ� ���� ����� ���� �����ϵ��� ���α׷��� �ۼ��ϼ���. (Hint: Ư�� ���� ����, ���ڿ� ��ü)
// #include <iostream>
// #include <string>
// using namespace std;
// string removeChar(string str, char c); //�����ϼ���. string findAndReplace(string str, string olds, string news); //�����ϼ���.
// int main() {
//     string str;
//     char c;
//     cout << "���ڿ� �Է�: ";
//     getline(cin, str);
//     cout << "�����ϰ��� �ϴ� ���� �Է� : ";
//     cin >> c;
//     cout << "���� �� ���ڿ� = " << removeChar(str, c) << endl << endl;
//     string str1 = "an old string";
//     string str2("an old");
//     string str3("a new");
//     cout << str1 << "���� ";
//     string strnew = findAndReplace(str1, str2, str3);
//     cout << str2 << " ���ڿ��� " << str3 << "�� ��ü �� ���ڿ� = " << strnew << endl;
//     return 0;
// }

#include <iostream>
#include <string>

using namespace std;

string removeChar(string str, char c) {
    while (str.find(c) != -1) {
        str.erase(str.find(c), 1);
    }
    return str;
}

string findAndReplace(string str, string olds, string news) {
    if (str.find(olds) != -1) {
        str.replace(str.find(olds), olds.length(), news);
    }
    return str;
}

int main() {
    string str;
    char c;

    cout << "���ڿ� �Է� : ";
    getline(cin, str);
    cout << "�����ϰ��� �ϴ� ���� �Է� : ";
    cin >> c;
    cout << "���� �� ���ڿ� = " << removeChar(str, c) << endl << endl;

    string str1 = "an old string";
    string str2("an old");
    string str3("a new");

    cout << str1 << "����";
    string strnew = findAndReplace(str1, str2, str3);
    cout << str2 << " ���ڿ���" << str3 << "�� ��ü �� ���ڿ� = " << strnew << endl;
    return 0;
}

// 10. �Ʒ��� ���õ� main() �Լ��� �����Ͽ� ���� ����� ���� �����ϵ��� untilFive() �Լ��� �ۼ��ϼ���. ��, main() �Լ��� �������� �ʰ� ���α׷��� �ۼ��ϰ� string_view Ŭ���� ����մϴ�.
// int main() {
//     string stra, outstr;
//     cout << "Enter a string: ";
//     getline(cin, stra);
//     outstr = untilFive(stra);
//     cout << " -> " << outstr;
//     char strb[50];
//     cout << "\nEnter a string: ";
//     gets(strb);
//     outstr = untilFive(strb);
//     cout << " -> " << outstr;
//     return 0;
// }

#include <iostream> // g++ ~~~.cpp -std=c++17 -o ~~~ Ŀ�ǵ�� �����ؾ���  
#include <string>
#include <string_view>
#include <cstdio>

using namespace std;

string_view untilFive(string_view str) {
    return str.substr(0, 5);
}

int main() {
    string stra, outstr;
    cout << "Enter a string: ";
    getline(cin, stra);

    outstr = untilFive(stra);
    cout << " -> " << outstr;

    char strb[50];
    cout << "\nEnter a string: ";
    gets(strb);
    outstr = untilFive(strb);
    cout << " -> " << outstr;

    return 0;
}

// ����
// 3. ���� �ڵ忡�� �߸��� �κ��� �����ϼ���.
// int x = 1000;
// int& y = 2000;
// ��� ��������� ������ ������ �Ұ����ϹǷ� �߸���

// 4. ���� �ڵ忡�� �߸��� �κ��� �����ϼ���.
// const int x = 100;
// double& y = x;
// x�� const�� ���� ������ �Ұ����� ����� �Ǿ������� ���������� �Ҵ��Ϸ� ����
// x�� int�� �����̹Ƿ� y�� �������µ� ���� ����

// 5. ���� �ڵ��� ���� ����� �����ϼ���.
// 10 10

// 6. ���� �ڵ��� ���� ����� �����ϼ���.
// int x = 100;
// int& y = x;
// int& z = x;
// cout << x << " " << y << " " << z;
// 100 100 100

// 7. Circle ��ü a�� ���� �������� ref�� �����ϴ� ������ �����ϼ���.
// ��:  
// Circle a;
// Circle &ref = a;

// 8. ������ ������ ���� ȣ���� ����Ͽ� swap() �Լ��� ȣ���ϴ� �����Դϴ�. swap() �Լ� ȣ�� �Ŀ��� �� ������ ������ ���� �ٲ�ϴ�. swap() �Լ��� ������ �����ϼ���.
// int a=60, b=90; 
// swap(a,b);

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a=60, b=90; 
    swap(a,b);
    cout << a << b << endl;
}

// 9. �ּ��� �ش��ϴ� ������ �����ϼ���.
// int array[]={3,5,3,2,1,7};
// int& f(int a){
//     return array[a];
// }
// ___________________; //�Լ� f�� �����Ͽ� �迭 array�� �׹�° ���Ҹ� 60���� ����

#include <iostream>

int array[] = {3, 5, 3, 2, 1, 7};

int& f(int a) {
    return array[a];
}

int main() {
    f(3) = 60;
}

// 10. �Ʒ��� ���õ� �Լ� ������ main() �Լ��� �����Ͽ� ���� ����� �����ϼ���.
// #include <iostream>
//     using namespace std;
//     char &find2replace(char *fstr, char re, bool &success) {
//     int i = 0;
//     while (*fstr) {
//         if (*fstr == re) {
//             success = true; //�߰���. �Լ� ����
//             return *fstr;
//         }
//     fstr++;
//     }
//     return *fstr; //�߰����� ����, return �� �ǹ� ����
// }
//
// int main() {
//     char str[] = "C++ programming";
//     char has = '+';
//     char replace = 'p';
//     bool result = false;
//
//     cout << "���� �� ���ڿ� = " << str << endl;
//
//     find2replace(str, has, result) = replace; //'+' ��ġ�� 'p' ����
//     
//     if (result == true) 
//         cout << "���� �� ���ڿ� = " << str << endl;
//     else 
//         cout << str << "���� " << has << "�� �߰����� ����." << endl;
//     return 0;
// }
// Cp+ programming

// 11. �Ʒ��� ���õ� main() �Լ��� �������� �����Ͽ� �� 10�� ������ ������ �κ��� �ذ� �� �� �ִ� find2replace() �Լ��� �ۼ��ϼ���. ��, find2replace() �Լ��� ��� �Ű������� ������ ����մϴ�.

#include <iostream>

using namespace std;

void find2replace(string& str, string& has, string& rep, bool& result) {
    while (str.find(has) != -1) {
        str.replace(str.find(has), has.length(), rep);
        result = true;
    }
}

int main()
{
    cout << "20195138 ����ȣ" << endl;
    std::string str = "C++ programming";
    std::string has = "+";
    string replace = "p";
    bool result = false;

    cout << "���� �� ���ڿ� = " << str << endl;

    find2replace(str, has, replace, result);

    if (result == true)
        cout << "���� �� ���ڿ� = " << str << endl;
    else
        cout << str << "���� " << has << "�� �߰����� ����." << endl;
    return 0;
}

