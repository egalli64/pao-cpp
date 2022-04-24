#include <iostream>
#include <memory>
#include "../Thing.h"

int main() {
    int* p = new int(42);
    std::cout << "Streaming a raw ptr gives its address: " << p;
    std::cout << ", use asterisk to get its value: " << *p << '\n';

    std::shared_ptr<int> sp{ p };
    std::cout << "Streaming a shared ptr gives its resource address: " << sp;
    std::cout << ", use asterisk to get its value: " << *sp << '\n';

    std::shared_ptr<Thing> spt{ new Thing{42} };
    std::cout << "Same if resource is a class instance: " << spt << ", value: " << *spt << '\n';
    std::cout << "Member access through the arrow operator: ";
    spt->hello();

    Thing* pt = spt.get();
    std::cout << "Access by raw pointer: ";
    pt->hello();

    std::cout << "REMEMBER! The object is owned by the smart pointer!\n";
    std::cout << "!!! DO NOT DELETE the raw pointer !!!\n";
}
