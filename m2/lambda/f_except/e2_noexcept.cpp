#include <cmath>
#include <exception>
#include <iostream>

int main() {
    []() noexcept {std::cout << "No exception!\n";}();

    auto mySqrt = [](int x) noexcept {
        return sqrt(x);
    };

    std::cout << "Result is: " << mySqrt(42) << '\n';
    std::cout << "Result is: " << mySqrt(-42) << '\n';
}
