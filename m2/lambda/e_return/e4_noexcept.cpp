#include <cmath>
#include <exception>
#include <iostream>

int main() {
    auto mySqrt = [](int x) noexcept {
        return sqrt(x);
    };

    std::cout << "Result is: " << mySqrt(42) << '\n';
    std::cout << "Result is: " << mySqrt(-42) << '\n';
}
