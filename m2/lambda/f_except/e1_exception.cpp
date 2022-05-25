#include <cmath>
#include <exception>
#include <iostream>

int main() {
    try {
        [] { throw std::runtime_error{ "Hello!" }; }();
    }
    catch (std::runtime_error& ex) {
        std::cout << ex.what() << '\n';
    }

    auto mySqrt = [](int x) {
        if (x < 0) {
            throw std::runtime_error{ "Value should not be negative" };
        }
        return sqrt(x);
    };
    std::cout << "Result is: " << mySqrt(42) << '\n';
    try {
        std::cout << "Result is: " << mySqrt(-42) << '\n';
    }
    catch (std::runtime_error& ex) {
        std::cout << ex.what() << '\n';
    }
}
