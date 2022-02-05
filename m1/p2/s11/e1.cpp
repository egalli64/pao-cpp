#include <iostream>
using namespace std;

int values[10];

int main() {
    cout << "size of an int[10] " << sizeof(values) << endl;
    cout << "size of char[3] " << sizeof(char[3]) << endl;
    cout << "size of double[3] " << sizeof(int[3]) << endl;
    cout << endl;
    cout << "Non-local arrays are default-initialized: " << values[0] << ' ' << values[9] << endl;

    int localValues[10];
    cout << "No assumption on local arrays: " << localValues[0] << ' ' << localValues[9] << endl;

    int data[6]{ 42, 12, 18, 21, 5, 33 };
    cout << "The last value in data: " << data[5] << endl;

    int data_len = sizeof(data) / sizeof(int);
    cout << "Length of data: " << data_len << endl;
    cout << "The last value in data (using sizeof): " << data[data_len - 1] << endl;
    cout << "This is a mistake: " << data[data_len] << endl;

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
