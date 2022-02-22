#include <iostream>
#include <memory>
#include "Base.h"
using namespace std;

void deleteByAssignment() {
    cout << "Unique ptr 1" << endl;
    unique_ptr<Base> up = make_unique<Base>(1);

    cout << "up: " << *up << endl;

    cout << "Deleting the object owned by up" << endl;
    up = nullptr;
    if (up) {
        cout << "Unexpected" << endl;
    }
    else {
        cout << "up is empty" << endl;
    }
}

void deleteByReset() {
    cout << "\nUnique ptr 2" << endl;
    unique_ptr<Base> up = make_unique<Base>(2);

    cout << "up: " << *up << endl;

    cout << "Deleting the object owned by up" << endl;
    up.reset();
    if (up) {
        cout << "Unexpected" << endl;
    }
    else {
        cout << "up is empty" << endl;
    }
}

void reassign() {
    cout << "\nUnique ptr 3" << endl;
    unique_ptr<Base> up = make_unique<Base>(3);

    cout << "up: " << *up << endl;

    cout << "Reassigning the object owned by up" << endl;
    up.reset(new Base(4));
    cout << "up: " << *up << endl;
}

void release() {
    cout << "\nUnique ptr 5" << endl;
    unique_ptr<Base> up = make_unique<Base>(5);

    cout << "up: " << *up << endl;

    cout << "Releasing the object owned by up" << endl;
    Base* p = up.release();
    if(!up) {
        cout << "Now up is empty" << endl;
    }

    cout << "Remember to delete the object by hand!" << endl;
    delete p;
}

int main() {
    deleteByAssignment();
    deleteByReset();
    reassign();
    release();
}
