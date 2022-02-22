#include <iostream>
#include <memory>
#include "Base.h"
using namespace std;

void empty() {
    cout << "An empty shared ptr" << endl;
    shared_ptr<Base> pEmpty;
    if (pEmpty) {
        cout << "Unexpected!" << endl;
    }
    cout << "---" << endl;
}

int main() {
    empty();

    cout << "A non-empty shared ptr" << endl;
    shared_ptr<Base> sp = make_shared<Base>(1);
    if (!sp) {
        cout << "Unexpected!" << endl;
    }

    cout << "Dereferencing: " << *sp << endl;
    cout << "Calling a method: ";
    sp->hello();

    Base* p = sp.get();
    cout << "Through a naked point: ";
    p->hello();
    cout << "DANGEROUS! The object is owned by the smart pointer!" << endl;
    cout << "!!! DO NOT DELETE the naked pointer !!!" << endl;

    cout << "---" << endl;
}
