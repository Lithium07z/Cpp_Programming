#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <cstring>
#include <string_view> //string_view Ŭ����

using namespace std;

//�پ��� Ÿ���� ���ڿ� ó���� ���� �Լ� �����ε�
string extractExt(const string filename) {
    cout << "1)";
    return filename.substr(filename.find('.'));
}
char* extractExt(const char* filename) {
    cout << "2)";
    char *p = nullptr;
    p = const_cast<char*>(strchr(filename, '.'));
    return p;
}

//string_view Ŭ���� ���
string_view extractExt(string_view filename) {
    return filename.substr(filename.find('.'));
}

int main() {
    string filename = "C:\temp\file.string";
    cout << extractExt(filename) << endl;
    
    char cfilename[ ] = "C:\temp\file.cstring";
    cout << extractExt(cfilename) << endl;
    
    cout << extractExt("C:\temp\file.literal") << endl;
    return 0;
}