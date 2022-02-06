#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void print(const vector<T>& values, const string& label) {
    cout << label << ": ";
    for (const T& value : values) {
        cout << value << ' ';
    }
    cout << endl;
}

int main() {
    vector<int> given{ 6, 4, 3 };
    print(given, "A vector with a few given values");

    given.resize(4);
    print(given, "After resizing (growing)");

    given.resize(2);
    print(given, "After resizing (shrinking)");

    given.resize(4, 2);
    print(given, "After resizing, (growing, given value)");
}