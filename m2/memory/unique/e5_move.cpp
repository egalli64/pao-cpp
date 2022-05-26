#include <iostream>
#include <memory>
#include "../ThingExt.h"

std::unique_ptr<Thing> getUnique() {
    std::unique_ptr<Thing> up = std::make_unique<ThingExt>(1);
    std::cout << "Returning a unique_ptr: ";
    up->hello();

    // moving a local object in a return statement prevents copy elision!
    // return std::move(up);

    return up;
}

void passUnique(std::unique_ptr<Thing> up) {
    std::cout << "A unique_ptr has moved in: ";
    up->hello();

    up.reset(new ThingExt{ 2 });
    std::cout << "Reset for unique_ptr: ";
    up->hello();
}

int main() {
    std::unique_ptr<Thing> up = getUnique();

    // won't compile
    // passUnique(up);

    passUnique(std::move(up));

    if (!up) {
        std::cout << "As expected, the unique smart pointer has no object associated anymore\n";
    }
}
