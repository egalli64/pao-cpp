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
    virtual string fullName() = 0;
};

class Dog : public Animal {
private:
    string owner_;
public:
    Dog(const string& name, const string& owner) : Animal(name), owner_(owner) {}

    string fullName() override final
    {
        return Animal::name() + " owned by " + owner_;
    }
};

class Poodle : public Dog {
public:
    Poodle(const string& name, const string& owner) : Dog(name, owner) {}

    // can't override a final method
    // string fullName() override { return "Poodle " + Dog::fullName(); }
};

int main() {
    Dog bob("Bob", "Robert Smith");
    cout << bob.fullName() << endl;

    Poodle tom("Tom", "Thomas Benson");
    cout << tom.fullName() << endl;
}
