#include <iostream>
#include <memory>
#include "Derived.h"
using namespace std;

void raw() {
    cout << "Raw pointer" << endl;
    Base* d1 = new Derived(1);
    d1->hello();
    delete d1;
}

void unique() {
    cout << "\nUnique smart pointer" << endl;
    unique_ptr<Base> up = make_unique<Derived>(2);
    up->hello();
}

unique_ptr<Base> getUnique() {
    cout << "\nMoving a unique smart pointer out" << endl;
    unique_ptr<Base> up = make_unique<Derived>(3);
    up->hello();

    return up;
}

void giveUnique(unique_ptr<Base> up) {
    cout << "\nA unique smart pointer is moved in" << endl;
    up->hello();

    up.reset(new Derived(4));
    cout << "\nUnique smart pointer reset" << endl;
    up->hello();
}

int main() {
    raw();
    unique();

    unique_ptr<Base> up3 = getUnique();

    giveUnique(move(up3));

    if (!up3) {
        cout << "\nAs expected, the unique smart pointer has no object associated anymore" << endl;
    }

    cout << "Last statement in main" << endl;
}
