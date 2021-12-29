#include <iostream>
using namespace std;

int main()
{
    int data[6] = { 42, 12, 18, 21, 5, 33 };
    cout << "Element in last position: " << data[5] << endl;

    int value = 84;
    int* ptr = &value;
    cout << "A single int variable, address and value: " << ptr << " -> " << *ptr << endl;

    // a pointer could change its referred memory location
    ptr = &data[0];
    cout << "First cell in an array, address and value: " << ptr << " -> " << *ptr << endl;

    ptr = data;
    cout << "Same: " << ptr << " -> " << *ptr << endl;

    ptr = &data[5];
    cout << "Last cell: " << ptr << " -> " << *ptr << endl;

    // a reference won't change its referred memory location
    int& ref = value;
    cout << "ref and value " << ref << ' ' << value << endl;

    ref += 1;
    cout << "ref and value after increasing ref " << ref << ' ' << value << endl;

    int& ref2 = data[5];
    cout << "ref2 and data[5] " << ref2 << ' ' << data[5] << endl;

    ref2 += 1;
    cout << "ref2 and data[5] after increasing ref2 " << ref2 << ' ' << data[5] << endl;
}
