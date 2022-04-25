#include <iostream>
using namespace std;

// static_assert(sizeof(int) == 8, "int should be 8 bytes");

int main() {
    int i = 1'000'000'000'000'000'000;
    cout << "i = " << i << endl;
}
