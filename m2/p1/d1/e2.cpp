#include <iostream>
#include <memory>
using namespace std;

class Base {
private:
    const int x_;
public:
    Base(int x) : x_(x) {}

    virtual void hello() const {
        cout << "Base hello " << x_ << endl;
    }

    virtual ~Base() {
        cout << "Base dtor " << x_ << endl;
    }
};


class Derived : public Base {
public:
    Derived(int x) : Base(x) {}

    void hello() const override {
        cout << "Derived ";
        Base::hello();
    }

    ~Derived() {
        cout << "Derived dtor" << endl;
    }
};

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

unique_ptr<Base> uniqueMoved() {
    cout << "\nReturning a unique smart pointer" << endl;
    unique_ptr<Base> up = make_unique<Derived>(3);
    up->hello();

    return up;
}

int main() {
    raw();
    unique();

    unique_ptr<Base> up3 = uniqueMoved();

    cout << "Last statement in main" << endl;
}
