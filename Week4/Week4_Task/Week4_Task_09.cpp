#include <iostream>

int array[] = {3, 5, 3, 2, 1, 7};

int& f(int a) {
    return array[a];
}

int main() {
    f(3) = 60;
}