#include <iostream>
using namespace std;

void swap(int& left, int& right) {
    int temp = left;
    left = right;
    right = temp;
}

int main() {
    int a = 42;
    int b = 18;

    cout << "a is " << a << " and b is " << b << endl;

    swap(a, b);
    cout << "a is " << a << " and b is " << b << endl;
}
