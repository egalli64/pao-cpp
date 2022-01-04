#include <iostream>
using namespace std;

static int values[10];

int main() {
    cout << "int[10] " << sizeof(values) << endl;
    cout << "char[3] " << sizeof(char[3]) << endl;
    cout << "double[3] " << sizeof(int[3]) << endl;
    cout << endl;
    cout << "Non-local arrays are default-initialized: " << values[0] << ' ' << values[9] << endl;

    int localValues[10];
    cout << "No assumption on local arrays: " << localValues[0] << ' ' << localValues[9] << endl;

    int data[6]{ 42, 12, 18, 21, 5, 33 };
    cout << "The last value in data: " << data[5] << endl;

    int* ptr = &data[0];
    cout << "First cell in data, address and value: " << ptr << " -> " << *ptr << endl;

    ptr = data;
    cout << "Same: " << ptr << " -> " << *ptr << endl;

    ptr = &data[5];
    cout << "Last cell: " << ptr << " -> " << *ptr << endl;

    int& ref = data[5];
    cout << "ref and data[5] " << ref << ' ' << data[5] << endl;

    ref += 1;
    cout << "ref and data[5] after increasing ref " << ref << ' ' << data[5] << endl;
}
