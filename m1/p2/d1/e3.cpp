#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "\nInitialization\n\n";
    int x = 42.7; // implicit narrowing

    //	int y {42.7}; // error: explicit narrowing required

    int y{ static_cast<int>(42.7) };
    auto z = 42.7; // automatic type deduction (here: double)

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << " sized " << sizeof(z) << endl;

    string s = "42";
    int i = stoi(s);
    cout << "From string to int (pre-incremented): " << ++i << endl;

    s += ".27";
    double d = stod(s);
    cout << "From string to double: " << d << endl;

    cout << "From numeric to string, and concat: " << to_string(51) + to_string(8.931255) << endl;
}
