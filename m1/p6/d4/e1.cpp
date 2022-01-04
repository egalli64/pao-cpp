#include <iostream>
using namespace std;

/**
 * @brief A final class
 */
class Animal final {
private:
    string name_;
public:
    Animal(const string& name) : name_(name) {}

    const string& name() const { return name_; }
};

/**
 * @brief can't extend a final class
 */
 // class Dog : public Animal {};

int main() {
    Animal tom("Tom");
    cout << tom.name() << endl;
}
