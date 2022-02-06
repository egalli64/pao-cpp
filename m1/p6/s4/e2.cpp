#include <iostream>
using namespace std;

class Animal {
private:
    string name_;
public:
    Animal(const string& name) : name_(name) {}

    virtual string name() const { return name_; }
};

class PolimorphicDog : public Animal {
private:
    string owner_;
public:
    PolimorphicDog(const string& name, const string& owner) : Animal(name), owner_(owner) {}

    string name() const override {
        return Animal::name() + " owned by " + owner_;
    }
};

void badIdea(Animal byValue) {
    cout << "Animal passed by value: " << byValue.name() << endl;
}

void normal(const Animal& byConstRef) {
    cout << "Animal passed by const reference: " << byConstRef.name() << endl;
}

int main() {
    Animal npas[] = { Animal("Tom"), PolimorphicDog("Bob", "Robert Smith") };
    cout << "Looping on animals in a non-polimorphic way" << endl;
    for (Animal a : npas) {
        cout << a.name() << endl;
    }

    Animal tom("Tom");
    cout << "An animal: " << tom.name() << endl;

    PolimorphicDog bob("Bob", "Robert Smith");
    cout << "A polimorphic dog: " << bob.name() << endl;

    cout << "Looping on the animals in a polimorphic way" << endl;
    Animal* animals[] = { &tom, &bob };
    for (Animal* pa : animals) {
        cout << pa->name() << endl;
    }

    badIdea(*animals[1]);
    normal(*animals[1]);
}
