// 2. 다음과 같은 디폴트 매개변수를 갖는 함수를 호출할 때 컴파일 오류가 발생하는 문장을 모두 고르세요.
// void msg(char id, int pass, string text="Hello");
// A. msg('a', 20);
// 
// B. msg(); 
// 매개변수가 없음
// C. msg('b', 30, "default");
// 
// D. msg("C++"); 
// 필수로 받아야하는 char, int 매개변수가 없음
// E. msg('b', "default");
// 필수로 받아야 하는 int 매개변수가 없음

// 3. 아래의 함수를 실행한 결과를 출력 할 수 있는 문장을 모두 제시하세요.
// int sum(int a, int b, int c=30) {
//     return a + b + c;
// }

sum(1, 2, 3);
sum(1, 2);

// 4. 아래의 함수를 실행한 결과를 출력 할 수 있는 문장을 모두 제시하세요.
// double sum(double a=3.4, double b=6.5) {
//     return a + b;
// }

sum();
sum(1.2);
sum(1.2, 3.4);

// 5. 다음과 같이 선언된 함수에서 오류가 발생하는 원인을 제시하고 수정하세요.
// int calc(int a, int b=5, int c, int d=0)
// A. 디폴트 매개변수가 중간에 위치해 있어서 오류가 발생함
//    int calc(int a, int b=5, int c=0, int d=0)

// 6. 다음 함수 호출이 가능하도록 디폴트 매개변수를 갖는 함수를 제시하세요.
// int main() {
//     cout << "sum = " << sum(2, 6, 5) << endl;
//     cout << "sum = " << sum(3.5, 5.6) << endl;
//     cout << "sum = " << sum(5, 12) << endl;
// }

double sum(double a, double b, double c = 0) {
    return a + b + c;
}

// 7. 다음 두 개의 중복 함수를 디폴트 매개변수를 갖는 하나의 함수로 작성하세요.
// void fillLine(int n) { 
//     for(int i=0; i<n; i++) cout << '#';
//     cout << endl;
// }
// void fillLine(int n, char c) { 
//     for(int i=0; i<n; i++) cout << c;
//     cout << endl;
// }

void fillLine(int n, char c = '#') {
    for(int i = 0; i < n; i++) cout << c;
    cout << endl;
}

// 8. Test 클래스를 사용한 다음 문제의 해법을 제시하세요.
// class Test {
// public:
//     static int cnt; 
//     static void print(); 
// };
// A. static 멤버 함수를 호출하는 방법을 모두 제시하세요.
// Test::print();
// Test t; t.print();
// Test *tp; tp = &t; tp->print();
// B. static 멤버 변수에 대한 외부 선언 문장을 제시하세요.
// int Test::cnt = 10;
// C. static 멤버 변수에 대한 외부 선언이 필요 없도록 선언하는 문장을 제시하세요.
// inline static int cnt;

// 9. 실행결과를 참고하여 main() 함수에서 Person 클래스 타입의 객체를 생성할 때 모든 객체를 하나의 생성자로 처리 할 수 있도록 프로그램을 완성하세요.
#include <iostream>

using namespace std;

class Person
{
    int id;
    double weight;
    string name;
public:
    Person(int id = 1, string name = "Grace", double weight = 20.5) : id{id}, name{name}, weight{weight} {};
    void show() { cout << id << ' ' << weight << ' ' << name << endl; }
};

int main()
{
    Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
    grace.show();
    ashley.show();
    helen.show();
}

// 10. 함수 big()을 호출하는 경우는 다음과 같습니다. 디폴트 매개변수를 가진 하나의 함수로 big()을 작성하세요.
#include <iostream>

using namespace std;

int big(int x, int y, int z = 100) {
    int temp = (x >= y)? x : y;
    return (temp >= z)? z : temp;
}

int main()
{
    int x = big(3, 5);       // 3과 5중 큰 값 5는 최대값 100보다 작으므로, 5 리턴
    int y = big(300, 60);    // 300과 60중 큰 값 300이 최대값 100보다 크므로, 100 리턴
    int z = big(30, 60, 50); // 30과 60 중 큰 값 60이 최대값 50보다 크므로, 50 리턴
    cout << x << ' ' << y << ' ' << z << endl;
}

// 11. 디폴트 매개변수를 갖는 하나의 add() 함수를 작성하고 프로그램을 완성 하세요.
#include <iostream>

using namespace std;

int add(int arrA[], int index, int arrB[] = nullptr) {
    int sum = 0;
    for (int i = 0; i < index; i++) {
        if (arrB != nullptr) {
            sum += arrB[i];
        }
        sum += arrA[i];
    }
    return sum;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {6, 7, 8, 9, 10};

    int c = add(a, sizeof(a) / sizeof(int));    //배열 a의 정수를 size 인덱스까지 모두 더한 값 리턴
    int d = add(a, sizeof(a) / sizeof(int), b); //배열 a, b의 정수를 size 인덱스까지 모두 더한 값 리턴

    cout << c << endl;                          // 15 출력
    cout << d << endl;                          // 55 출력
}

// 12. ArrayUtil 클래스의 static 함수인 concat()은 두 개의 배열을 연결한 새로운 배열을 동적 생성하여 
// 리턴합니다. ArrayUtil 클래스의 static 함수인 remove()는 앞 배열에서 뒤 배열의 있는 숫자를 모두 
// 삭제한 새로운 배열을 동적 생성하여 리턴합니다. 아래에 제시된 ArrayUtil 클래스와 실행화면을 
// 참고하여 프로그램을 완성 하세요.

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class ArrayUtil
{
public:
    // s1과 s2를 연결한 새로운 배열을 동적 생성하여 리턴
    static int *concat(int s1[], int size1, int s2[], int size2, int &retSize);
    // s1에서 s2에 있는 숫자를 모두 삭제한 새로운 배열을 동적 생성하여 리턴
    static int *remove(int s1[], int size1, int s2[], int size2, int &retSize);
};

int *ArrayUtil::concat(int s1[], int size1, int s2[], int size2, int &retSize)
{
    retSize = size1 + size2;
    int *temp = new int[retSize];

    for (int i = 0; i < retSize; i++)
    {
        if (i < size1)
        {
            temp[i] = s1[i];
        }
        else
        {
            temp[i] = s2[i - size1];
        }
    }
    return temp;
}

int *ArrayUtil::remove(int s1[], int size1, int s2[], int size2, int &retSize)
{
    retSize = 0;
    int *temp = new int[size1];

    for (int i = 0; i < size1; i++)
    {
        int check = -1;
        for (int j = 0; j < size2; j++)
        {
            if (s1[i] == s2[j])
            {
                check++;
            }
        }
        if (check == -1)
        {
            temp[retSize++] = s1[i];
        }
    }

    int *arr = new int[retSize];

    for (int i = 0; i < retSize; i++)
    {
        arr[i] = temp[i];
    }

    return arr;
}

int main()
{
    int xcount = 0, ycount = 0;
    int *x, *y;

    cout << "사이즈 입력 : ";
    cin >> xcount;

    x = new int[xcount];

    for (int i = 0; i < xcount; i++)
    {
        cin >> x[i];
    }

    cout << "사이즈 입력 : ";
    cin >> ycount;

    y = new int[ycount];

    for (int i = 0; i < ycount; i++)
    {
        cin >> y[i];
    }

    int retsize = 0;

    int *conarr = ArrayUtil::concat(x, xcount, y, ycount, retsize);

    cout << "\nx배열과 y배열을 연결한 배열은 ";
    for (int i = 0; i < retsize; i++)
        cout << conarr[i] << ' ';
    cout << endl;

    int *remarr = ArrayUtil::remove(x, xcount, y, ycount, retsize);

    cout << "\nx배열에서 y배열의 원소를 삭제한 결과, x배열의 개수는 " << retsize << "개, ";
    for (int i = 0; i < retsize; i++)
        cout << remarr[i] << ' ';
    cout << endl;

    delete x, y, conarr, remarr;
}