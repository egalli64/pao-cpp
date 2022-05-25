#include <iostream>
#include <limits>

int main() {
    auto v1 = []() -> char {return 'x';}();
    std::cout << "The returned char: " << v1 << ", size: " << sizeof(v1) << '\n';

    auto v2 = []() -> int {return 'x';}();
    std::cout << "The returned int: " << v2 << ", size: " << sizeof(v2) << '\n';

    // overflow in conversion from double to (max) int
    auto v2a = []() -> int {return 2e300;}();
    std::cout << "The returned int: " << v2a << ", size: " << sizeof(v2a) << '\n';

    auto v3 = []() -> long double {return 42;}();
    std::cout << "The returned long double: " << v3 << ", size: " << sizeof(v3) << '\n';

    // !!! floating constant exceeds range of double -> inf
    auto v3a = []() -> long double {return 1e400;}();
    std::cout << "The returned long double: " << v3a << ", size: " << sizeof(v3a) << '\n';
}
