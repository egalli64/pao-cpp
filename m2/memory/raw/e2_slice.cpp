#include <iostream>
#include <memory>
#include "../ThingExt.h"

void slice() {
    std::cout << "The slicing problem\n";

    ThingExt te{ 1 };
    std::cout << "Original hello: ";
    te.hello();

    Thing t = te;
    std::cout << "Sliced hello: ";
    t.hello();
}

void noSlice() {
    std::cout << "Solving the slicing problem\n";

    Thing* pt = new ThingExt{ 2 };
    std::cout << "Full hello: ";
    pt->hello();
    delete pt;
}

int main() {
    slice();
    noSlice();
}
