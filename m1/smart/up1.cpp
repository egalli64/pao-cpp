#include <iostream>
#include <memory>
#include "Base.h"
using namespace std;

void empty() {
    cout << "An empty unique ptr" << endl;
    unique_ptr<Base> pEmpty;
    if (pEmpty) {
        cout << "Unexpected!" << endl;
    }
    cout << "---" << endl;
}

int main() {
    empty();

    cout << "A non-empty unique ptr" << endl;
    unique_ptr<Base> up = make_unique<Base>(1);
    if (!up) {
        cout << "Unexpected!" << endl;
    }

    cout << "Dereferencing: " << *up << endl;
    cout << "Calling a method: ";
    up->hello();

    Base* p = up.get();
    cout << "Through a naked point: ";
    p->hello();
    cout << "DANGEROUS! The object is owned by the smart pointer!" << endl;
    cout << "!!! DO NOT DELETE the naked pointer !!!" << endl;

    cout << "---" << endl;
}
