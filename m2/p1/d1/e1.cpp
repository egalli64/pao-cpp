#include <iostream>
using namespace std;

int main() {
    char c = 'x';
    cout << "A char on the stack: " << c << endl;

    char* pz = new char{ 'Z' };
    cout << "A char on the heap: " << *pz << endl;
    delete pz;

    int sData[6]{ 1,2,3 };
    cout << "An array of int on the stack: ";
    for (int cur : sData) {
        cout << cur << ' ';
    }
    cout << endl;

    int* hData = new int[6]{ 1,2,3 };
    cout << "An array of int on the heap: ";
    for (int i = 0; i < 6; ++i) {
        cout << hData[i] << ' ';
    }
    cout << endl;
    delete[] hData;
}
