#include <iostream>
using namespace std;

int main() {
    auto v1 = [] {return 'x';}();
    cout << "A char returned by a lambda: " << v1 << ", size: " << sizeof(v1) << '\n';

    auto v2 = [] {return 42;}();
    cout << "An int returned by a lambda: " << v2 << ", size: " << sizeof(v2) << '\n';

    auto v2a = [] {return 42'000'000'000;}();
    cout << "A long int returned by a lambda: " << v2a << ", size: " << sizeof(v2a) << '\n';

    auto v3 = [] {return 42.7;}();
    cout << "A double returned by a lambda: " << v3 << ", size: " << sizeof(v3) << '\n';

    auto v3a = [] {return 42.7F;}();
    cout << "A float returned by a lambda: " << v3a << ", size: " << sizeof(v3a) << '\n';

    auto myLambda = []() -> long double {return 42;};
    auto result = myLambda();
    // same as:
    // auto result = []() -> long double {return 42;}();

    cout << "A long double explicitely returned by a lambda: " << result << ", size: " << sizeof(result) << '\n';
}
