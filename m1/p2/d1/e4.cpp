#include <iostream>
using namespace std;

int main() {
    cout << "\nConstants\n\n";
    constexpr auto x = 18; // evaluated at compile time

    //	x += 1; // error!

    const auto y = 42; // won't change

    //	y += 1; // error!

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}
