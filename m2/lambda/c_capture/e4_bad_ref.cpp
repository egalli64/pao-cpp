#include <functional>
#include <iostream>

namespace {
    std::function<void()> veryBad() {
        int x = 42;

        auto result = [&x]() { std::cout << "Captured is " << x << '\n'; };

        std::cout << "Inside function is alright. ";
        result();

        return result;
    }
}

int main() {
    auto lambda = veryBad();

    std::cout << "Undefined behavior, reference to a variable out of scope! ";
    lambda();
}
