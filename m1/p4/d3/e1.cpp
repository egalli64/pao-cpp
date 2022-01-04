#include <iostream>
using namespace std;

void wontSwap(int left, int right) {
    cout << "left is " << left << " and right is " << right << endl;

    int temp = left;
    left = right;
    right = temp;

    cout << "left is " << left << " and right is " << right << endl;
}

int main() {
    int a = 42;
    int b = 18;

    cout << "a is " << a << " and b is " << b << endl;

    wontSwap(a, b);
    cout << "a is " << a << " and b is " << b << endl;
}
