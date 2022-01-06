#include <iostream>
using namespace std;

class Tail {
private:
    int count_;
public:
    Tail(int count) : count_(count) {}

    void wag(const string& name) const {
        cout << name << ": ";
        for (int i = 0; i < count_; ++i) {
            cout << "wag";
        }
        cout << endl;
    }
};

/**
 * @brief Dog has-a Tail
 */
class Dog : private Tail {
private:
    string name_;
public:
    Dog(const string& name, int count) : Tail(count), name_(name) {}

    void bark() {
        cout << name_ << ": bark!" << endl;
        wag(name_);
    }
};

int main() {
    Dog tom("Tom", 3);
    tom.bark();
    // Tail methods are not part of the dog interface
    // tom.wag();
}
