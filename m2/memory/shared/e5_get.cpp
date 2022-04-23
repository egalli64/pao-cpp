#include <iostream>
#include <memory>
#include "../Base.h"

int main() {
    std::cout << "Getter on shared ptr\n";
    std::shared_ptr<Base> sp(new Base(42));

    Base* p = sp.get();
    std::cout << "Access by raw pointer: ";
    p->hello();
    
    std::cout << "REMEMBER! The object is owned by the smart pointer!\n";
    std::cout << "!!! DO NOT DELETE the raw pointer !!!\n";
}
