#include <iostream>
using namespace std;

int main() {
    bool b_false = false;
    bool b_true = true;
    bool b_narrowed = 42;
    cout << "Boolean in C++ is actually a very small integer: " << b_false << ", ";
    cout << b_true << ", " << b_narrowed << endl;

    char c = 'x';
    cout << "A character: " << c << endl;

    int i = 49'385; // optional digit separator C++14
    cout << "An int: " << i << endl;

    double d = 3.14159'26535;
    cout << "A double: " << d << endl;

    signed short int ssi = 0xFFFF; //  Hexadecimal notation
    unsigned short int usi = 0xFFFF;
    cout << "A signed short integer: " << ssi << " and an unsigned short int: " << usi << endl;

    string s = "Hello";
    cout << "A string: " << s << endl;

    int i_widened = c;
    cout << "A char implicitly converted to int: " << i_widened << endl;
}
