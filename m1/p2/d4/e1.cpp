#include <iostream>
using namespace std;

int main() {
    char c = 'x';
    char* pc = new char;
    *pc = 'z';
    cout << c << ' ' << *pc << endl;
    delete pc;

    int sData[6] { 1,2,3,4,5,6 };
    int* hData = new int[6];
    hData[0] = 42;
    hData[5] = 3;
    cout << sData[0] << ' ' << hData[0] << endl;
    delete[] hData;

    cout << "done" << endl;
}
