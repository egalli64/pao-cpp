#include <iostream>
using namespace std;

class Animal
{
private:
    string name_;
public:
    Animal(const string& name) : name_(name) {}

    virtual string name() { return "Animal " + name_; }
};

class PolimorphicDog : public Animal
{
private:
    string owner_;
public:
    PolimorphicDog(const string& name, const string& owner) : Animal(name), owner_(owner) {}

    string name() override
    {
        return Animal::name() + " owned by " + owner_;
    }
};

int main()
{
    Animal tom("Tom");
    cout << tom.name() << endl;

    PolimorphicDog bob("Bob", "Robert Smith");
    cout << bob.name() << endl;

    cout << "Looping on the animals in a polimorphic way" << endl;
    Animal* animals[] = { &tom, &bob };
    for (Animal* pa : animals)
    {
        cout << pa->name() << endl;
    }
}
