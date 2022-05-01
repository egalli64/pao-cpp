#include <iostream>

int main() {
    int a = 1;
    int b = 2;
    int c = 3;
    std::cout << "Initial values: " << a << ", " << b << ", " << c << '\n';

    // all required by value, but b by reference
    [=, &b] { std::cout << "Increasing b (by ref), summing a and b: " << a + ++b << '\n'; }();
    std::cout << "b has changed: " << b << '\n';

    // all required by reference, but b by value
    [&, b] { std::cout << "Increasing a (by ref), summing a and b: " << ++a + b << '\n'; }();
    std::cout << "a has changed: " << a << '\n';
}
