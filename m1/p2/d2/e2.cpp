#include <iostream>
using namespace std;

int main()
{
    int value = 84;
    int* ptr = &value;
    cout << "A single int variable, address and value: " << ptr << " -> " << *ptr << endl;

    // a pointer could change its referred memory location
    int other = 27;
    ptr = &other;
    cout << "The int 'other', address and value: " << ptr << " -> " << *ptr << endl;

    // a reference won't change its referred memory location
    int& ref = value;
    cout << "ref and value " << ref << ' ' << value << endl;

    ref += 1;
    cout << "ref and value after increasing ref " << ref << ' ' << value << endl;
}
