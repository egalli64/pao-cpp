#include <iostream>

int main() {
    // return type is deduced as double
    auto square = [] (double value) {
        return value * value;
    };

    double original = 42.24;
    std::cout << original << " squared is " << square(original) << '\n';
}
