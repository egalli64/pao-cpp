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

    cout << "\nString concatenation\n\n";
    string s{ "Hello" };
    string t{ "World!" };
    cout << s + ", " + t << endl;
}
