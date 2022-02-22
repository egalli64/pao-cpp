#include <iostream>
#include <memory>
#include "Base.h"
using namespace std;

int main() {
    cout << "A shared ptr" << endl;
    shared_ptr<Base> sp = make_shared<Base>(1);

    cout << "\nReset the shared ptr with a new object" << endl;
    sp.reset(new Base(2));

    cout << "\nReset the shared ptr to empty" << endl;
    sp.reset();
    if (!sp) {
        cout << "The sp now is empty" << endl;
    }

    cout << "\nReset the shared ptr with a new object" << endl;
    sp.reset(new Base(3));

    cout << "\nReset the shared ptr to empty by assigment" << endl;
    sp = nullptr;
    if (!sp) {
        cout << "The sp now is empty" << endl;
    }
}
