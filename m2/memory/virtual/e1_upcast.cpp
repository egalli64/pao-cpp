#include <iostream>
#include <memory>
#include "../ThingExt.h"

void raw() {
    std::cout << "*** Raw pointer for object in a hierarchy ***\n";
    ThingExt* pte = new ThingExt{ 42 };
    std::cout << "Says hello: ";
    pte->hello();

    Thing* pt = pte;
    std::cout << "Upcasting: ";
    pt->hello();

    std::cout << "Explicit delete from base pointer\n";
    delete pt;
}

void smart() {
    std::cout << "*** Smart pointer for object in a hierarchy ***\n";
    std::unique_ptr<ThingExt> upte = std::make_unique<ThingExt>(42);
    std::cout << "Says hello: ";
    upte->hello();

    std::unique_ptr<Thing> upt = std::move(upte);
    if (!upte && upt) {
        std::cout << "Resource moved and upcasted: ";
        upt->hello();
    }
    else {
        std::cout << "Unexpected\n";
    }
}

int main() {
    raw();
    smart();
}
