#include <iostream>
using namespace std;

void swap(int* pLeft, int* pRight) {
    cout << "Called by pointer: left is " << *pLeft << " and right is " << *pRight << endl;

    int temp = *pLeft;
    *pLeft = *pRight;
    *pRight = temp;

    cout << "Called by pointer: left is " << *pLeft << " and right is " << *pRight << endl;
}

int main() {
    int a = 42;
    int b = 18;

    cout << "Caller by pointer: a is " << a << " and b is " << b << endl;

    swap(&a, &b);
    cout << "Caller by pointer: a is " << a << " and b is " << b << endl;
}
