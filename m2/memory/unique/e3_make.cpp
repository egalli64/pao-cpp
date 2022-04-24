#include <iostream>
#include <memory>

int main() {
    std::cout << "Prefer creating unique ptr by make_unique\n";
    std::unique_ptr<int> up = std::make_unique<int>(42);
    if (up) {
        std::cout << "Value is " << *up << '\n';
    }
    else {
        std::cout << "Unexpected!\n";
    }
}
