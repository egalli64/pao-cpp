#include <iostream>
using namespace std;

int main() {
    int a; // a is declared as int, but not initialized
    // when compiled with -Wall flag -> warning: access to uninitialized variable
    cout << "!!! BAD IDEA !!! " << a << endl;

    a = 5; // a is initialized to 5
    cout << a << endl;

    // variable definition preferred to split declaration and initialization
    int b = 7;
    cout << b << endl;

    // assignment, changing value in a variable
    b = 42;
    cout << b << endl;
}
