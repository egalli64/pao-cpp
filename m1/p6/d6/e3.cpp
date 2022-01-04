#include <iostream>
using namespace std;

class Actor {
private:
    string name_;
public:
    Actor() { cout << "Default Actor" << endl; }
    Actor(const string& name) : name_(name) {
        cout << "Actor ctor for " << name << endl;
    }
    ~Actor() { cout << "Actor dtor for " << name_ << endl; }

    const string& name() const { return name_; }
};

class Animal : virtual public Actor {
public:
    Animal(const string& name) : Actor(name) {
        cout << "Animal ctor for " << name << endl;
    }
    ~Animal() { cout << "Animal dtor" << endl; }
};

class Player : virtual public Actor {
private:
    string game_;
public:
    Player(const string& name, const string& game) : Actor(name), game_(game) {
        cout << "Player ctor for " << game << endl;
    }
    ~Player() { cout << "Player dtor for " << game_ << endl; }

    const string& game() const { return game_; }
};

class Dog : public Animal, Player {
public:
    Dog(const string& name, const string& game) : Animal(name), Player(name, game), Actor(name) {
        cout << "Dog ctor" << endl;
    }

    void message() {
        cout << name() << " likes playing " << game() << endl;
    }
};

int main() {
    Dog tom("Tom", "chess");
    tom.message();
}
