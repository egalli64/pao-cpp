#include <iostream>
#include <memory>
#include "../Thing.h"

int main() {
    int* p = new int{ 42 };
    std::cout << "Streaming a raw ptr gives its address: " << p;
    std::cout << ", use asterisk to get its value: " << *p << '\n';

    std::unique_ptr<int> up{ p };
    // C++20
    // std::cout << "Streaming a shared ptr gives its resource address: " << up << '\n';
    std::cout << "Use asterisk to get the resource value: " << *up << '\n';

    std::unique_ptr<Thing> upt{ new Thing{42} };
    // C++20
    // std::cout << "Same if resource is a class instance: " << upt << '\n';
    std::cout << "Same if resource is a class instance: " << *upt << '\n';
    std::cout << "Member access through the arrow operator: ";
    upt->hello();

    Thing* pt = upt.get();
    std::cout << "Access by raw pointer: ";
    pt->hello();

    std::cout << "REMEMBER! The object is owned by the smart pointer!\n";
    std::cout << "!!! DO NOT DELETE the raw pointer !!!\n";

    Thing* ptr = upt.release();
    std::cout << "Access by raw pointer _released_ from smart pointer: ";
    pt->hello();

    std::cout << "The object is _not_ owned anymore by the smart pointer!\n";
    std::cout << "!!! REMEMBER TO DELETE the raw pointer !!!\n";
    delete ptr;
}
