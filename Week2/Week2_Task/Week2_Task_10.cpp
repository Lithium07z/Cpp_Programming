#include <iostream>
#include <iomanip>

int main() {
    int quiz;
    double first;
    int final;
    std::cout << "퀴즈, 중간고사, 기말고사 성적을 입력하세요 : ";
    std::cin >> quiz >> first >> final;

    std::cout << "total : " << quiz + first + final << std:: endl;
    std::cout << "average : " << std::fixed << std::setprecision(2) << (quiz + first + final) / 3;

    return 0;
}