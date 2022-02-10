#include <cctype>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    cout << "The caller ";
    if (argc == 1) {
        cout << "didn't pass any argument\n";
    }
    else if (argc == 2) {
        cout << "passed a argument: " << argv[1] << endl;
        if (isdigit(argv[1][0])) {
            cout << "First char is a digit!" << endl;
        }
    }
    else if (argc % 2) {
        cout << "passed an even number of arguments\n";
    }
    else {
        cout << "passed an odd number of arguments\n";
    }
}
