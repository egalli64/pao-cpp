#include <iostream>
using namespace std;

int main() {
    char c = 'x';
    cout << "An initialized char on the stack: " << c << endl;

    char* pc = new char;
    cout << "An uninitialized char on the heap: " << static_cast<int>(*pc) << endl;
    delete pc;

    char* pz = new char{'Z'};
    cout << "An initialized char on the heap: " << *pz << endl;
    delete pz;

    int sData[6]{ 1,2,3 };
    cout << "First element in an array on the stack: " << sData[0] << endl;
    cout << "Last element in an array on the stack: " << sData[5] << endl;

    int* hData = new int[6]{ 1,2,3 };
    cout << "First element in an array on the stack: " << hData[0] << endl;
    cout << "Last element in an array on the stack: " << hData[5] << endl;
    delete[] hData;
}
