#include <iostream>
using namespace std;

class Actor {
private:
    string name_;
public:
    Actor(const string& name) : name_(name) {
        cout << "Actor ctor for " << name << endl;
    }
    ~Actor() { cout << "Actor dtor for " << name_ << endl; }

    const string& name() const { return name_; }
};

class Animal : public Actor {
public:
    Animal(const string& name) : Actor(name) {
        cout << "Animal ctor for " << name << endl;
    }
    ~Animal() { cout << "Animal dtor" << endl; }
};

class Player : public Actor {
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
    Dog(const string& name, const string& game) : Animal(name), Player(name, game) {
        cout << "Dog ctor" << endl;
    }

    void message() {
        // ambiguous! name as animal or as player?
        // cout << name() << " likes playing " << game() << endl;

        // explicitly choosing the "right" name 
        cout << Player::name() << " likes playing " << game() << endl;
    }
};

int main() {
    Dog tom("Tom", "chess");
    tom.message();
}
