#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <cstring>
#include <string_view> //string_view 클래스

using namespace std;

//다양한 타입의 문자열 처리를 위해 함수 오버로딩
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

//string_view 클래스 사용
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