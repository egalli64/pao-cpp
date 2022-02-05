#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    switch (argc) {
    default:
        cout << "The last parameter is " << argv[argc - 1] << endl;
        // !!! FALL THROUGH - DO NOT BREAK HERE !!!
    case 2:
        cout << "The first parameter is " << argv[1] << endl;
        // !!! FALL THROUGH - DO NOT BREAK HERE !!!
    case 1:
        cout << "The program has been invoked with name " << argv[0] << endl;
        break;
    }
}
