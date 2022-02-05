#include <iostream>
using namespace std;

void swap(int& left, int& right) {
    cout << "Called by reference: left is " << left << " and right is " << right << endl;

    int temp = left;
    left = right;
    right = temp;
    cout << "Called by reference: left is " << left << " and right is " << right << endl;
}

int main() {
    int a = 42;
    int b = 18;

    cout << "Caller by reference: a is " << a << " and b is " << b << endl;

    swap(a, b);
    cout << "Caller by reference: a is " << a << " and b is " << b << endl;
}
