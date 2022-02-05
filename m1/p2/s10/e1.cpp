#include <iostream>
using namespace std;

int main() {
    cout << "Null pointer\n\n";

    int* ptr = nullptr;
    cout << "An unused pointer: " << ptr << endl;
    cout << "A null pointer can't be dereferenced ... " << endl;

    cout << *ptr << endl;
}
