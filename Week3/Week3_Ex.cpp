// 2. 빈 괄호를 채워 넣으세요. 
// A. C++는 ( )언어와의 호환성과 ( ) 개념 추가를 목표로 설계되었다.
// Q. C++는 (C)언어와의 호환성과 (객체지향) 개념 추가를 목표로 설계되었다.

// B. C++ 프로그램의 확장자는 ( ) 이다.
// Q. C++ 프로그램의 확장자는 (cpp) 이다.

// C. ( )헤더 파일은 표준 입출력을 위한 클래스와 객체, 변수 등이 선언되어 있다.
// Q. (iostream)헤더 파일은 표준 입출력을 위한 클래스와 객체, 변수 등이 선언되어 있다.

// D. 이름 공간을 생략하려면 ( )지시어를 사용한다. 
// Q. 이름 공간을 생략하려면 (using)지시어를 사용한다.

// E. 표준 입력 장치인 키보드로 데이터를 입력 받을 때 ( ) 객체를 사용한다.
// Q. 표준 입력 장치인 키보드로 데이터를 입력 받을 때 (cin) 객체를 사용한다.

// F. bool 타입으로 선언된 변수에 저장된 값을 불 리터럴로 출력하려면 조작자 ( )를 사용해야 한다.
// Q. bool 타입으로 선언된 변수에 저장된 값을 불 리터럴로 출력하려면 조작자 (boolalpha)를 사용해야 한다.

// G. const int *ptr = &val;의 의미는 ( )을 이용해서 ( )의 값을 변경할 수 없음을 의미한다.
// Q. const int *ptr = &val;의 의미는 (포인터)을 이용해서 (val)의 값을 변경할 수 없음을 의미한다.

// H. uniform initialization는 ( )을 사용하여 변수, 배열, 객체 등을 초기화 한다.
// Q. uniform initialization는 ({}, 중괄호)을 사용하여 변수, 배열, 객체 등을 초기화 한다.

// 8. 다음 중 컴파일 오류가 발생하는 문장은 무엇인가요?
// int d {3. 6};
// int f = 3.6;

// 정답
// int d {3.6}; 
// 실수를 정수형으로 축소변환 불가능 

// 9. 다음 프로그램을 cpp로 수정한 소스와 결과를 함께 제시하세요. auto변수로 변환 가능한 곳은 모두 변경하세요.
//#include <stdio.h>
//  int sum(int s, int e); // 함수 원형 선언
//  int sum(int s, int e) {
//  int tmp, res = 0;
//   
//  if(s>e) {
//      tmp = e;
//      e = s;
//      s = tmp;
//  }
//  for (int k = s; k <= e; k++) {
//      res += k;
//  }
//      return res;
//}
//
//  int main() {
//      int a, b;
//      printf("첫 수와 마지막 수를 입력하세요 : ");
//      scanf("%d %d", &a, &b);
//      printf("%d부터 %d까지의 합은 %d 입니다\n", a, b, sum(a, b));
//      return 0;
//  }

// 정답
#include <iostream>

using namespace std;

auto sum(int s, int e); // 함수 원형 선언

auto sum(int s, int e) {
    auto tmp = 0;
    auto res = 0;

    if (s > e) {
        tmp = e;
        e = s;
        s = tmp;
    }
    for (auto k = s; k <= e; k++) {
        res += k;
    }
    return res;
}

int main()
{
    auto a = 0;
    auto b = 0;
    cout << "첫 수와 마지막 수를 입력하세요 : ";
    cin >> a >> b;
    cout << a << "부터 " << b << "까지의 합은 " << sum(a, b) << " 입니다." << endl;
    return 0;
}

// 13. 입력된 실수에서 정수 부분과 소수점 아랫부분을 분리해서 출력하는 프로그램을 실행화면을 참고하여 작성하세요. (Hint: static_cast)
// 정답
#include <iostream>

using namespace std;

int main() {
    double value = 0;

    cout << "실수를 입력하세요 : ";
    cin >> value; 

    cout << "정수 part : " << static_cast<int>(value) << endl;
    cout << "소수 part : " << value - static_cast<int>(value);

    return 0;
}

// 14. 제시된 main() 함수와 실행 결과를 참고하여 두 번째 인수와 가장 가까운 거리에 있는 문자를 출력하는 프로그램을 완성하세요. (Hint: initializer_list)
// 정답
#include <iostream>
#include <initializer_list>

using namespace std;

char list_exam(initializer_list<int> value, int word) { 
    int min = 1000000;
    int result = 0;

    for (int temp : value) {
        int sub = abs(temp - word);
        if (min > sub) {
            min = sub;
            result = temp;
        }
    }
    return result;
}

int main() {
    cout << "{ 'd', 'p', 'r', 'w', 'g', 'f' }문자 중 h와 가까운 문자는 : " ;
    cout << list_exam({ 'd', 'p', 'r', 'w', 'g', 'f' }, 'h') << endl;
    cout << "{ 'k', 'q', 'b', 'r', 'a', 'e', 'v', 'z'}문자 중 w와 가까운 문자는 : ";
    cout << list_exam({ 'k', 'q', 'b', 'r', 'a', 'e', 'v', 'z'}, 'w') << endl;
}

// 15. 사용자에게 정수를 입력받아 배열에 저장한 후 배열의 내용을 오름차순으로 정렬하는 프로그램을 실행화면을 참고하여 작성하세요. (Hint: sort(array.begin(), array.end()))
// 정답
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main() {
    cout << "정수 입력 : ";

    array<int, 5> arr;
    for (auto i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }

    cout << "배열에 저장된 내용 : ";
    for (auto i = 0; i < arr.size(); i++) {
        cout << arr.at(i) << " ";
    }
    cout << endl << "배열 오름차순 정렬 : ";

    sort(arr.begin(), arr.end());
    for (auto temp : arr) {
        cout << temp << " ";
    }
    return 0;
}