#include <iostream>
#include <memory>
#include "../Thing.h"

int main() {
    std::unique_ptr<Thing> sp = std::make_unique<Thing>(1);

    std::cout << "Resetting\n";
    sp.reset(new Thing{ 2 });

    std::cout << "Resetting to nullptr: ";
    sp.reset();

    std::cout << "Resetting on an empty unique ptr: ";
    sp.reset(new Thing{ 3 });

    std::cout << "Resetting to nullptr by assignment: ";
    sp = nullptr;
}
