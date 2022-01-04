#include <iostream>
using namespace std;

int main() {
    cout << "bool " << sizeof(bool) << endl;
    cout << "char " << sizeof(char) << endl;
    cout << "short " << sizeof(short) << endl;
    cout << "int " << sizeof(int) << endl;
    cout << "long " << sizeof(long) << endl;
    cout << "long long " << sizeof(long long) << endl;
    cout << endl;

    cout << "float " << sizeof(float) << endl;
    cout << "double " << sizeof(double) << endl;
    cout << "long double " << sizeof(long double) << endl;
    cout << endl;

    bool b = true; // actually, 1
    char c = 'x';
    int i = 49'385; // optional digit separator C++14
    double d = 3.14159'26535;
    cout << b << ' ' << c << ' ' << i << ' ' << d << endl;

    signed short int ssi = 0xFFFF; //  Hexadecimal notation
    unsigned short int usi = 0xFFFF;
    cout << "signed short integer: " << ssi << ", unsigned short int: " << usi << endl;

    cout << "\nImplicit convertions, both widening and narrowing\n";
    int ci = c;
    bool bi = i;
    cout << c << " -> " << ci << " ... " << i << " -> " << bi << endl;
}
