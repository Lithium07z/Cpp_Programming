// 3. 질문에 답하세요
// A. C++ 표준 라이브러리 그룹 3개를 설명하세요.
// Q. C 라이브러리, C++ 입출력 라이브러리, C++ STL 라이브러리

// B. C++ 프로그램이 실행을 시작하는 함수 원형을 제시하시오.
// Q. int main(void)

// C. C++ 표준에서 cin, cout 객체는 어떤 헤더 파일에 선언되어 있나요?
// Q. <iostream>

// D. C++ 표준 라이브러리가 모두 선언된 이름 공간은 무엇인가요?
// Q. std::

// E. 이름공간을 선언할 때 사용하는 키워드는 무엇인가요?
// Q. namespace

// F. namespace hallym에 정의된 함수 software()를 호출하는 문장을 쓰세요. 단, software() 함수는 반환 값과 매개변수를 가지지 않습니다.
// Q. hallym::software

// G. 다음 문장에 오류가 발생하지 않도록 수정하세요. using 지시어는 사용하지 않습니다.
// Q. std::cout <<  "C++";

// H. 컴파일 때 변수에 초기화 된 값으로 형을 결정하는 자료형은 무엇인가?
// Q. auto

// 4. 다음 문장 중에서 틀린 부분을 올바르게 수정하세요.
// #include <iostream.h> 
// using std namespace; 
// cin << data; 
// 100 >> cout;

// 정답 
#include <iostream>

using namespace std;

cin >> data;
cout << 100;

// 5. main()에서 이름 공간을 지정하는 문장을 사용하지 않으려고 합니다. 아래의 코드를 수정하세요.
// #include <iostream>
// #include <string>
// int main() {
// string name; 
// cout << "이름을 입력하세요 : "; 
// cin >> name; 
// cout << "name : " << name << endl; 
// return 0;
// }

// 정답
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "이름을 입력하세요 : ";
    std::cin >> name;
    std::cout << "name : " << name << std::endl;
    return 0;
}

// 6. 제시된 프로그램에 대하여 질문에 답하세요.
// #include <iostream>
// #include <string>
// using namespace std;
// int main() {
// string name;
// cout << "이름을 입력하세요 : ";
// cin >> name;
// cout << name << " 님 환영합니다 "<<endl;
// return 0;
// }

// A. 다음과 같이 키보드로 “C++”을 입력하였을 때 결과를 제시하세요.
// Q. C++ 님 환영합니다

// B. 다음과 같이 키보드로 “C++ OOP”을 입력하였을 때 결과를 제시하세요.
// Q. C++ 님 환영합니다

// 7. 컴파일 오류가 발생하지 않도록 빈칸을 채워 넣으세요.
// #include <iostream>
// _______________
// _______________
// int main() {
// int count;
// cout << "반복 횟수를 입력하세요 : ";
// std::cin >> count;
// cout << count << " 회 반복합니다. "<<endl;
// return 0;
// }

// 정답
#include <iostream>

using std::cout;
using std::endl;
 
int main() {
int count;
cout << "반복 횟수를 입력하세요 : ";
std::cin >> count;
cout << count << " 회 반복합니다. "<< endl;
return 0;
}