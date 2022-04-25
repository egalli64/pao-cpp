#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    if (argc == 1) {
        // Can't do anything sensible without any argument
        throw 42;
    }

    cout << "The first argument is: " << argv[1] << endl;
}
