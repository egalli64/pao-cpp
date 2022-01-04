#include <iostream>
using namespace std;

void sayHello(int count = 1) {
    cout << "...";
    for (int i = 0; i < count; ++i) {
        cout << " hello";
    }
    cout << "!" << endl;
}

int main() {
    sayHello(3);
    sayHello();
}
