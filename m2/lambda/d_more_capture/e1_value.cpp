#include <iostream>

int main() {
    int a = 1;
    int b = 2;
    int c = 3;
    std::cout << "Initial values: " << a << ", " << b << ", " << c << '\n';

    // IIFE (Immediately Invoked Function Expression)
    [] { std::cout << "Hello\n"; }();

    // won't compile: no variable captured
    // [] { std::cout << << a << '\n'; }();

    // all required variables captured by value
    [=] { std::cout << "Summing a and b: " << a + b << '\n'; }();

    // same result
    [a, b] { std::cout << "Summing a and b: " << a + b << '\n'; }();

    // won't compile: variable captured by value is not modifiable
    // [a] { a++; }();
}
