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