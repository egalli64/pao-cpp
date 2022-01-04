#include <iostream>
using namespace std;

int main() {
    cout << "char* " << sizeof(char*) << endl;
    cout << "double* " << sizeof(double*) << endl;
    cout << endl;

    char c = 'x';
    char* pc = &c;

    cout << c << ' ' << *pc << endl;
    *pc = 'z';
    cout << c << ' ' << *pc << endl;
}
