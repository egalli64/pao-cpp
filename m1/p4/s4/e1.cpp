#include <iostream>
using namespace std;

void wontSwap(int left, int right) {
    cout << "Called by value: left is " << left << " and right is " << right << endl;

    int temp = left;
    left = right;
    right = temp;

    cout << "Called by value: left is " << left << " and right is " << right << endl;
}

int main() {
    int a = 42;
    int b = 18;

    cout << "Caller by value: a is " << a << " and b is " << b << endl;

    wontSwap(a, b);
    cout << "Caller by value: a is " << a << " and b is " << b << endl;
}
