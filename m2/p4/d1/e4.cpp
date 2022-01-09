#include <iostream>
using namespace std;

void risky(int value) {
    if (value == 1) {
        throw 42;
    }
    cout << "Hello" << endl;
}

int main(int argc, char** argv) {
    try {
        risky(argc);
    }
    catch (int exc) {
        cout << "Error detected: " << exc << endl;
        cout << "You should pass at least an argument to this program!" << endl;
    }

    cout << "Rest of code" << endl;
}
