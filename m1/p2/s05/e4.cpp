#include <iostream>
using namespace std;

int main() {
    int x = 42;
    int y = 18;

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;


    cout << "\nAssignment operators\n\n";
    cout << "x += y -> x = " << (x += y) << endl;
    cout << "x -= y -> x = " << (x -= y) << endl;
    cout << "++x -> x = " << ++x << endl;
    cout << "--x -> x = " << --x << endl;
}
