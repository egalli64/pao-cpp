#include <iostream>
#include <limits>

int main() {
    auto v1 = [] {return 'x';}();
    std::cout << "The returned char: " << v1 << ", size: " << sizeof(v1) << '\n';


    auto v2 = [] {return 42;}();
    std::cout << "The returned int: " << v2 << ", size: " << sizeof(v2) << '\n';

    auto v2a = [] {return 5'000'000'000;}();
    std::cout << "The returned long int: " << v2a << ", size: " << sizeof(v2a) << '\n';


    auto v3 = [] {return 3.6F;}();
    std::cout << "The returned float: " << v3 << ", size: " << sizeof(v3) << '\n';

    auto v3a = [] {return std::numeric_limits<double>::max();}();
    std::cout << "The returned double: " << v3a << ", size: " << sizeof(v3a) << '\n';


    auto v4 = [] {return 1e400L;}();
    std::cout << "The returned long double: " << v4 << ", size: " << sizeof(v4) << '\n';

    auto v4a = [] {return std::numeric_limits<long double>::max();}();
    std::cout << "The returned long double: " << v4a << ", size: " << sizeof(v4a) << '\n';
}
