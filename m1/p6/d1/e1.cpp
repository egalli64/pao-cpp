#include <iostream>
using namespace std;

class Animal {
private:
    string name_;
public:
    Animal(const string& name) : name_(name) {}

    const string& name() const { return name_; }
};

class Dog : public Animal {
private:
    string owner_;
public:
    Dog(const string& name, const string& owner) : Animal(name), owner_(owner) {}

    const string& owner() const { return owner_; }
};

int main() {
    Animal tom("Tom");
    cout << tom.name() << endl;

    Dog bob("Bob", "Robert Smith");
    cout << bob.name() << " owned by " << bob.owner() << endl;
}
