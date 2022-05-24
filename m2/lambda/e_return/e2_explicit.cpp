#include <iostream>
using namespace std;

int main() {
    auto v1 = []() -> char {return 'x';}();
    cout << "The returned char: " << v1 << ", size: " << sizeof(v1) << '\n';

    auto v1a = []() -> int {return 'x';}();
    cout << "The returned int: " << v1a << ", size: " << sizeof(v1a) << '\n';

    // overflow in conversion from double to (max) int
    auto v2 = []() -> int {return 2e+300;}();
    cout << "The returned int: " << v2 << ", size: " << sizeof(v2) << '\n';
}
