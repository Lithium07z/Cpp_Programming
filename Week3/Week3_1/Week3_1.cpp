#include <iostream> // 헤더 파일에 .h안 붙임, c에서 쓰던거라면 <c string> 같은 형식으로 씀
#include <string>

using namespace std;

int main() {
    string str; // 빈 문자열을 가진 스트링 객체

    string address1("강원도 춘천시 한림대학길"); // 자바에서 생성자를 부르는 것과 같음
    string address2("강원도 춘천시 한림대학길", 6); // 앞의 내용 중 6byte만 문자열로 만들겠다는 뜻, address2 == "강원도";

    string copyAddress(address1);

    // getline()은 string 타입의 문자열을 입력받기 위해 제공되는 전역 함수
    // getline() 세번째 인수는 구분 기호(생략하면 \n)
    // 공백이 포함된 문자열 입력 가능
    getline(cin, str, 'c'); // 문자 'c'에서 입력 중지

    char text[] = {'L', 'o', 'v', 'e', ',', 'C', '+', '+', '\0'}; // 문자열 마지막에 null 추가
    string title(text); // C-스트링 (char[] 배열)으로부터 스트링 객체 생성

    auto string1 = "Hello cpp"; // const char*
    auto string2 = "Hello cpp"s; // str::string
}