#include <iostream>
using namespace std;

int main() {
    auto v1 = [] {return 'x';}();
    cout << "A char returned by a lambda: " << v1 << ", size: " << sizeof(v1) << endl;

    auto v2 = [] {return 42;}();
    cout << "An int returned by a lambda: " << v2 << ", size: " << sizeof(v2) << endl;

    auto v2a = [] {return 42'000'000'000;}();
    cout << "An int returned by a lambda: " << v2a << ", size: " << sizeof(v2a) << endl;

    auto v3 = [] {return 42.7;}();
    cout << "A double returned by a lambda: " << v3 << ", size: " << sizeof(v3) << endl;

    auto v3a = [] {return 42.7F;}();
    cout << "A float returned by a lambda: " << v3a << ", size: " << sizeof(v3a) << endl;

    auto v4 = []() -> long double {return 42;}();
    cout << "A long double explicitely returned by a lambda: " << v4 << ", size: " << sizeof(v4) << endl;
}
