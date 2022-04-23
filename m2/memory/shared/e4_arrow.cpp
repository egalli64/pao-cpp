#include <iostream>
#include <memory>
#include "../Base.h"

int main() {
    std::cout << "Accessing a member in a shared ptr\n";
    std::shared_ptr<Base> sp{ new Base(42) };
    std::cout << "Calling the hello method on the Base object: ";
    sp->hello();
}
