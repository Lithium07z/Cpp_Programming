// 문자열
// 4. 아래의 C 문자열을 활용하는 코드를 같은 결과가 나오도록 C++ 문자열을 이용해서 코드를 작성하세요.
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

// 5. 아래의 C 문자열을 활용하는 코드를 같은 결과가 나오도록 C++ 문자열을 이용해서 코드를 작성하세요. 
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

// 6. 다음 코드는 C 문자열의 첫번째 문자를 제거하는 코드입니다. 같은 결과가 나오도록 C++ 문자열을 활용해 코드를 작성하세요.
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

// 7. 아래의 C 문자열을 활용하는 코드를 같은 결과가 나오도록 C++ 문자열을 이용해서 코드를 작성하세요.
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
    // cout << str.erase(0, index) << endl; 도 가능
}

// 8. 다음과 같이 C 문자열을 활용하는 코드를 같은 결과가 나오도록 C++ 문자열로 코드를 작성하세요.
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

// 9. 아래에 제시된 함수 원형과 main() 함수를 참고하여 실행 결과와 같이 동작하도록 프로그램을 작성하세요. (Hint: 특정 문자 제거, 문자열 교체)
// #include <iostream>
// #include <string>
// using namespace std;
// string removeChar(string str, char c); //구현하세요. string findAndReplace(string str, string olds, string news); //구현하세요.
// int main() {
//     string str;
//     char c;
//     cout << "문자열 입력: ";
//     getline(cin, str);
//     cout << "삭제하고자 하는 문자 입력 : ";
//     cin >> c;
//     cout << "삭제 후 문자열 = " << removeChar(str, c) << endl << endl;
//     string str1 = "an old string";
//     string str2("an old");
//     string str3("a new");
//     cout << str1 << "에서 ";
//     string strnew = findAndReplace(str1, str2, str3);
//     cout << str2 << " 문자열을 " << str3 << "로 교체 후 문자열 = " << strnew << endl;
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

    cout << "문자열 입력 : ";
    getline(cin, str);
    cout << "삭제하고자 하는 문자 입력 : ";
    cin >> c;
    cout << "삭제 후 문자열 = " << removeChar(str, c) << endl << endl;

    string str1 = "an old string";
    string str2("an old");
    string str3("a new");

    cout << str1 << "에서";
    string strnew = findAndReplace(str1, str2, str3);
    cout << str2 << " 문자열을" << str3 << "로 교체 후 문자열 = " << strnew << endl;
    return 0;
}

// 10. 아래에 제시된 main() 함수를 참고하여 실행 결과와 같이 동작하도록 untilFive() 함수를 작성하세요. 단, main() 함수는 변경하지 않고 프로그램을 작성하고 string_view 클래스 사용합니다.
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

#include <iostream> // g++ ~~~.cpp -std=c++17 -o ~~~ 커맨드로 실행해야함  
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

// 참조
// 3. 다음 코드에서 잘못된 부분을 설명하세요.
// int x = 1000;
// int& y = 2000;
// 상수 대상으로의 참조자 선언은 불가능하므로 잘못됨

// 4. 다음 코드에서 잘못된 부분을 설명하세요.
// const int x = 100;
// double& y = x;
// x는 const로 인해 수정이 불가능한 상수가 되었음에도 참조변수에 할당하려 했음
// x는 int형 변수이므로 y의 변수형태도 맞지 않음

// 5. 다음 코드의 실행 결과를 제시하세요.
// 10 10

// 6. 다음 코드의 실행 결과를 제시하세요.
// int x = 100;
// int& y = x;
// int& z = x;
// cout << x << " " << y << " " << z;
// 100 100 100

// 7. Circle 객체 a에 대한 참조변수 ref를 선언하는 문장을 제시하세요.
// 답:  
// Circle a;
// Circle &ref = a;

// 8. 다음은 참조에 의한 호출을 사용하여 swap() 함수를 호출하는 문장입니다. swap() 함수 호출 후에는 두 변수의 내용이 서로 바뀝니다. swap() 함수의 원형만 제시하세요.
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

// 9. 주석에 해당하는 문장을 제시하세요.
// int array[]={3,5,3,2,1,7};
// int& f(int a){
//     return array[a];
// }
// ___________________; //함수 f를 실행하여 배열 array의 네번째 원소를 60으로 변경

#include <iostream>

int array[] = {3, 5, 3, 2, 1, 7};

int& f(int a) {
    return array[a];
}

int main() {
    f(3) = 60;
}

// 10. 아래에 제시된 함수 원형과 main() 함수를 참고하여 실행 결과를 예측하세요.
// #include <iostream>
//     using namespace std;
//     char &find2replace(char *fstr, char re, bool &success) {
//     int i = 0;
//     while (*fstr) {
//         if (*fstr == re) {
//             success = true; //발견함. 함수 성공
//             return *fstr;
//         }
//     fstr++;
//     }
//     return *fstr; //발견하지 못함, return 값 의미 없음
// }
//
// int main() {
//     char str[] = "C++ programming";
//     char has = '+';
//     char replace = 'p';
//     bool result = false;
//
//     cout << "변경 전 문자열 = " << str << endl;
//
//     find2replace(str, has, result) = replace; //'+' 위치에 'p' 저장
//     
//     if (result == true) 
//         cout << "변경 후 문자열 = " << str << endl;
//     else 
//         cout << str << "에서 " << has << "를 발견하지 못함." << endl;
//     return 0;
// }
// Cp+ programming

// 11. 아래에 제시된 main() 함수와 실행결과를 참고하여 위 10번 문제의 부족한 부분을 해결 할 수 있는 find2replace() 함수를 작성하세요. 단, find2replace() 함수의 모든 매개변수는 참조를 사용합니다.

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
    cout << "20195138 김준호" << endl;
    std::string str = "C++ programming";
    std::string has = "+";
    string replace = "p";
    bool result = false;

    cout << "변경 전 문자열 = " << str << endl;

    find2replace(str, has, replace, result);

    if (result == true)
        cout << "변경 후 문자열 = " << str << endl;
    else
        cout << str << "에서 " << has << "를 발견하지 못함." << endl;
    return 0;
}

