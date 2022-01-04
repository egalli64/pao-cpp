#include <iostream>
using namespace std;

class Tail {
private:
    int count_;
public:
    Tail(int count) : count_(count) {}

    void wag(const string& name) const {
        cout << name << ": ";
        for (int i = 0; i < count_; i++) {
            cout << "wag";
        }
        cout << endl;
    }
};

/**
 * @brief Dog has-a Tail, and shares its access to derived classes
 */
class Dog : protected Tail {
protected:
    string name_;
public:
    Dog(const string& name, int count) : Tail(count), name_(name) {}

    void bark() {
        cout << name_ << ": bark!" << endl;
        wag(name_);
    }

    virtual void eat() {
        cout << name_ << ": eat" << endl;
    }
};

class Poodle : public Dog {
public:
    Poodle(const string& name) : Dog(name, 2) {}

    void eat() override {
        cout << name_ << ": eat" << endl;
        wag(name_);
    }
};

int main() {
    Dog tom("Tom", 3);
    tom.bark();
    tom.eat();

    Poodle bob("Bob");
    bob.bark();
    bob.eat();
}
