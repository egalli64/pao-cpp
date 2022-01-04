#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int x = 42;
    int y = 18;

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    cout << "\nArithmetic operators\n\n";

    cout << "x + y = " << x + y << endl;
    cout << "+x = " << +x << endl;
    cout << "x - y = " << x - y << endl;
    cout << "-x = " << -x << endl;
    cout << "x * y = " << x * y << endl;
    cout << "x / y = " << x / y << endl;
    cout << "x % y = " << x % y << endl;

    cout << "\nComparison operators\n\n";

    cout << "x == y = " << (x == y) << endl;
    cout << "x != y = " << (x != y) << endl;
    cout << "x < y = " << (x < y) << endl;
    cout << "x <= y = " << (x <= y) << endl;
    cout << "x > y = " << (x > y) << endl;
    cout << "x >= y = " << (x >= y) << endl;

    cout << "\nLogical operators\n\n";
    cout << "x && y = " << (x && y) << endl;
    cout << "x || y = " << (x || y) << endl;
    cout << "!x = " << !x << endl;

    cout << "\nBitwise operators\n\n";
    cout << "x = " << bitset<8>(x) << endl;
    cout << "y = " << bitset<8>(y) << endl;
    cout << endl;

    cout << "x & y = " << bitset<8>(x & y) << endl;
    cout << "x | y = " << bitset<8>(x | y) << endl;
    cout << "x ^ y = " << bitset<8>(x ^ y) << endl;
    cout << "~x = " << bitset<8>(~x) << endl; // alt-126, altGr-ì

    cout << "\nAssignment operators\n\n";
    cout << "x += y -> x = " << (x += y) << endl;
    cout << "x -= y -> x = " << (x -= y) << endl;
    cout << "++x -> x = " << ++x << endl;
    cout << "--x -> x = " << --x << endl;
}
