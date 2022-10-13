#include <iostream>
#include <vector>

int main() { // vector ¿¹½Ã
    std::vector<int> aarr(5);

    for (int i = 0; i < 5; i++) {
        aarr[i] = i * 2;
    }

    for (int v : aarr) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    std::vector<int> barr{1, 2, 3, 4, 5};

    for (auto v : barr) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    barr.emplace_back(6);
    std::cout << "barr.size = " << barr.size() << std::endl;

    for (int v : barr) std::cout << v << " ";
    std::cout << std::endl;

    barr.pop_back();
    for (const int &v : barr) {
        std::cout << v << " ";
    }


}