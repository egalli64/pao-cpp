#include <iostream>
#include <memory>
using namespace std;
#include "Derived.h"

void other(shared_ptr<Base> sp) {
    cout << "\nAnother shared pointer on the same object" << endl;
    cout << "Use count: " << sp.use_count() << endl;
    sp->hello();
}

int main() {
    cout << "A shared pointer on a derived object" << endl;
    shared_ptr<Base> sp1 = std::make_shared<Derived>(1);
    cout << "Use count: " << sp1.use_count() << endl;
    sp1->hello();

    other(sp1);

    cout << "\nLast statement in main, use count: " << sp1.use_count() << endl;
}
