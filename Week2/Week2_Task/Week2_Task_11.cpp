#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
    int data;
    string menu;

    cout << "20195138, 김준호" << endl;
    cout << "10진수 입력 : ";
    cin >> data;

    cout << "여러 진법으로 출력 하기 oct(8), hex(16), digit(10)" << endl;

    while(1) {
        cout << "해당 진법 입력 : ";
        cin >> menu;
        
         if (menu.compare("8") == 0 || menu.compare("oct") == 0) {
            cout << " => 8진법 : 0" << oct << data << endl;
        } else if (menu.compare("16") == 0 || menu.compare("hex") == 0) {
            cout << " => 16진법 : 0x" << hex << data << endl;
        } else if (menu.compare("10") == 0 || menu.compare("digit") == 0) {
            cout << " => 10진법 : " << data << endl;
        } else {
            cout << "해당 진법이 없습니다.";
            break;
        }
    }
    return 0;
}