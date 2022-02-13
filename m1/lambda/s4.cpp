#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
    int a = 1;
    int b = 2;
    int c = 3;
    cout << "Initial values: " << a << ", " << b << ", " << c << endl;

    // all local variable captured by value
    [=] { cout << "Summing values: " << a + b + c << endl; }();

    // all by value, but c by reference
    [=, &c] { cout << "Summing values, increasing c (by ref): " << a + b + ++c << endl; }();
    cout << "c has changed: " << c << endl;

    // all by reference, but c by value
    [&, c] { cout << "Summing values, increasing a and b (by ref): " << ++a + ++b + c << endl; }();
    cout << "a and b have changed: " << a << ", " << b << endl;

    // by value mutable
    auto f1 = [a]() mutable { cout << "Increasing the captured 'a': " << ++a << endl; };
    for (int i = 0; i < 3; ++i) {
        f1();
        cout << "Original 'a': " << a << endl;
    }
}
