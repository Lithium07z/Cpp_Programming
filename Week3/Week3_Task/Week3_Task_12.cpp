#include <iostream>

using namespace std;

int main() {
    cout << "20195138, 김준호" << endl;
    int num = 0;
    enum class RPS {Rack = 1, Paper = 2, Scissors = 3};

    while (1) {
        cout << "정수 입력(1, 2, 3이 아닌 수는 프로그램 종료) : ";
        cin >> num;
        if (num == static_cast<int>(RPS::Rack)) {
            cout << "Rack" << endl;
        } else if (num == static_cast<int>(RPS::Paper)) {
            cout << "Paper" << endl;
        } else if (num == static_cast<int>(RPS::Scissors)) {
            cout << "Scissors" << endl;
        } else {
            break;
        }
    }
    return 0;
}