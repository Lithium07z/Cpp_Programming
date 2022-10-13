#include <iostream>
using namespace std;

void method(int i) {}
class Exam {
public:
    Exam() { cout << "Exam 디폴트 생성자" << endl; }
};

int main() {
    Exam e(); // Exam 타입을 반환하는 함수
    Exam ex{}; // 디폴트 생성자 호출
    //int d{ 3.6 }; // error, 축소 변환 불가
    int f = 3.6; // 컴파일 오류는 없지만 경고, 축소 변환
    int arr[]{2, 3, 4}; // 배열 초기화
    method(4.9);
    //method({ 4.9 }); // error, 축소 변환 불가
}