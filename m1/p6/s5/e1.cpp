#include <iostream>
using namespace std;

/**
 * @brief An abstract class
 */
class Animal {
private:
    string name_;
public:
    Animal(const string& name) : name_(name) {}

    const string& name() const { return name_; }
    // pure virtual method
    virtual string fullName() const = 0;
};

/**
 * @brief to be concrete it must override the base class abstract methods
 */
class Dog : public Animal {
private:
    string owner_;
public:
    Dog(const string& name, const string& owner) : Animal(name), owner_(owner) {}

    string fullName() const override {
        return Animal::name() + " owned by " + owner_;
    }
};

int main() {
    // Can't instantiate an abstract class
    // Animal animal("Tom");

    Dog bob("Bob", "Robert Smith");
    cout << bob.name() << endl;
    cout << bob.fullName() << endl;

    cout << "It is a polimorphic dog" << endl;
    Animal* pa = &bob;
    cout << pa->fullName() << endl;
}
