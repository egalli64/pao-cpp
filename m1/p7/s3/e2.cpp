#include <iostream>
#include <array>
using namespace std;

void print(const array<int, 3>& data) {
    for (int i = 0; i < data.size(); ++i) {
        cout << data[i] << ' ';
    }
    cout << endl;
}

int main() {
    array<int, 3> uninitialized;
    cout << "classic for loop on an uninitialized array: ";
    for (size_t i = 0; i < uninitialized.size(); ++i) {
        cout << uninitialized[i] << ' ';
    }
    cout << endl;

    print(uninitialized);

    array<int, 6> values{ 6, 4, 3 };
    cout << "loop by const iterator: ";
    // auto here is std::array<int, 6>::const_iterator
    for (auto it = values.cbegin(); it != values.cend(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    cout << "loop-increase by iterator: ";
    // auto here is std::array<int, 6>::iterator
    for (auto it = values.begin(); it != values.end(); ++it) {
        cout << ++(*it) << ' ';
    }
    cout << endl;

    cout << "range-for by value: ";
    for (int cur : values) {
        cout << cur << ' ';
    }
    cout << endl;

    cout << "range-for by const ref: ";
    for (const int& cur : values) {
        cout << cur << ' ';
    }
    cout << endl;
}
