#include <iostream>

int main() {
    char c = 'X';
    std::cout << "A char on the stack: " << c << '\n';

    char* pc = new char{ 'Y' };
    std::cout << "A char on the heap: " << *pc << '\n';
    delete pc;

    int sData[6]{ 1,2,3 };
    std::cout << "An array of int on the stack: ";
    for (int cur : sData) {
        std::cout << cur << ' ';
    }
    std::cout << '\n';

    int* hData = new int[6]{ 1,2,3 };
    std::cout << "An array of int on the heap: ";
    for (int i = 0; i < 6; ++i) {
        std::cout << hData[i] << ' ';
    }
    std::cout << '\n';
    delete[] hData;
}
