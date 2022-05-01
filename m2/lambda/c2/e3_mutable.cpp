#include <iostream>

int main() {
    int a = 1;

    // by value mutable
    [a]() mutable { std::cout << "Captured increased to " << ++a << '\n'; }();

    std::cout << "Original 'a' is still " << a << '\n';
}
