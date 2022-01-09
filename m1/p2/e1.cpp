#include <iostream>
using namespace std;

int main() {
    int a = 3; // type is "int", name is "a", value is "3"

    int b; // b is declared as int, but not initialized
    cout << "!!! BAD IDEA !!! " << b << endl; // access to uninitialized variable

    b = 5; // b is initialized to 5

    int c = 7; // c is defined as an int valued 7

    cout << a << endl; // access to a
    cout << b << endl;
    cout << c << endl;
}
