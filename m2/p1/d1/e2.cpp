#include <iostream>
#include <memory>
using namespace std;

class Base {
private:
    const int x_;
public:
    Base(int x) : x_{ x } {
        cout << "Base ctor " << x_ << endl;
    }

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

unique_ptr<Base> getUnique() {
    cout << "\nMoving a unique smart pointer out" << endl;
    unique_ptr<Base> up = make_unique<Derived>(3);
    up->hello();

    return up;
}

void giveUnique(unique_ptr<Base> up) {
    cout << "\nA unique smart pointer is moved in" << endl;
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
