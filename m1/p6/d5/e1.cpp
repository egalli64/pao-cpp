#include <iostream>
using namespace std;

class BadAnimal {
private:
    string name_;
public:
    BadAnimal(const string& name) : name_(name) {}
    ~BadAnimal() { cout << "Dtor for " << name_ << endl; }

    const string& name() const { return name_; }
    virtual string fullName() = 0;
};

class Dog : public BadAnimal {
private:
    string owner_;
public:
    Dog(const string& name, const string& owner) : BadAnimal(name), owner_(owner) {}
    ~Dog() { cout << "Dtor for dog owned by " << owner_ << endl; }

    string fullName() override {
        return BadAnimal::name() + " owned by " + owner_;
    }
};

void bobFunction() {
    Dog bob("Bob", "Robert Smith");
    cout << bob.fullName() << endl;
}

int main() {
    bobFunction();

    Dog* chip = new Dog("Chip", "Charlie Parker");
    cout << chip->fullName() << endl;
    delete chip;

    BadAnimal* dick = new Dog("Dick", "Douglas Adams");
    cout << dick->fullName() << endl;
    delete dick;
}
