#include <iostream>
using namespace std;

class Adder
{
private:
    int addendum_;

public:
    Adder(int addendum) : addendum_(addendum) {}

    int operator()(int value) const { return value + addendum_; }
};

int main()
{
    Adder add42(42);
    cout << add42(18) << endl;
}
