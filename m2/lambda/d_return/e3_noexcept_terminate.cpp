#include <cmath>
#include <exception>
#include <iostream>

int main() {
    try {
        // violating the noexcept contract!
        []() noexcept { throw std::runtime_error("Teminate!"); }();
    }
    catch (std::runtime_error& ex) {
        std::cout << "You won't see this!\n";
    }
}
