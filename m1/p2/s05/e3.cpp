#include <iostream>
#include <bitset>
using namespace std;

int main() {
    unsigned int x = 42;
    unsigned int y = 18;

    cout << "\nBitwise operators\n\n";
    cout << "x = " << x << " (" << bitset<8>(x) << ')' << endl;
    cout << "y = " << y << " (" << bitset<8>(y) << ')' << endl;
    cout << endl;

    cout << "x & y = " << bitset<8>(x & y) << endl;
    cout << "x | y = " << bitset<8>(x | y) << endl;
    cout << "x ^ y = " << bitset<8>(x ^ y) << endl;
    cout << "~x = " << bitset<8>(~x) << endl; // alt-126, altGr-ì
}
