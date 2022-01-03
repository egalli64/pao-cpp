#include <iostream>
using namespace std;

int main()
{
    cout << "\nInitialization\n\n";
    int x = 42.7; // implicit narrowing

    //	int y {42.7}; // error: explicit narrowing required

    int y{ int(42.7) };
    auto z = 42.7; // automatic type deduction (here: double)

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << " sized " << sizeof(z) << endl;
}
