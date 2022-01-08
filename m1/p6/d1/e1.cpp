#include <iostream>
using namespace std;

class Animal {
private:
    const string name_;
public:
    Animal() : name_("Unkwnown") {};
    Animal(const string& name) : name_(name) {}

    const string& name() const { return name_; }
};

ostream& operator<<(ostream& os, Animal animal) {
    return os << animal.name();
}

class Dog : public Animal {
private:
    const string owner_;
public:
    Dog() : owner_("none") {}
    Dog(const string& name, const string& owner) : Animal(name), owner_(owner) {}

    const string& owner() const { return owner_; }
};

ostream& operator<<(ostream& os, Dog dog) {
    return os << dog.name() << " owned by " << dog.owner();
}

int main() {
    Animal tom("Tom");
    cout << tom << endl;

    Dog bob("Bob", "Robert Smith");
    cout << bob << endl;

    Dog x;
    cout << x << endl;
}
