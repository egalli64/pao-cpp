#include <iostream>
#include <memory>
#include "../ThingExt.h"
#include "../ThingOther.h"

void raw() {
    std::cout << "*** Raw pointer for object in a hierarchy ***\n";
    Thing* pt = new ThingExt{ 42 };
    std::cout << "Says hello: ";
    pt->hello();

    // is it right to downcast?
    ThingOther* pto = dynamic_cast<ThingOther*>(pt);
    if (pto != nullptr) {
        std::cout << "Unexpected\n";
    }

    // I'm sure of what I'm doing, downcast it
    ThingExt* pte = static_cast<ThingExt*>(pt);
    std::cout << "Downcasting: ";
    pte->hello();

    std::cout << "Explicit delete\n";
    delete pte;
}

void smart() {
    std::cout << "*** Smart pointer for object in a hierarchy ***\n";
    std::shared_ptr<Thing> spt = std::make_shared<ThingExt>(42);
    std::cout << "Says hello: ";
    spt->hello();

    // is it right to downcast?
    std::shared_ptr<ThingOther> spto = std::dynamic_pointer_cast<ThingOther>(spt);
    if (spto) {
        std::cout << "Unexpected\n";
    }

    // I'm sure of what I'm doing, downcast it
    std::shared_ptr<ThingExt> spte = std::static_pointer_cast<ThingExt>(spt);
    if (!spte) {
        std::cout << "Unexpected\n";
    }
    else {
        std::cout << "Use count to the resource now is " << spte.use_count() << '\n';
    }
}

int main() {
    raw();
    smart();
}
