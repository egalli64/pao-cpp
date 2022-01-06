#include <iostream>
#include <array>
#include <string>
using namespace std;

void print(const array<int, 4>& values, const string& label) {
    cout << label << ": ";
    for (int cur : values) {
        cout << cur << ' ';
    }
    cout << endl;
}

int main() {
    array<int, 4> values{ 6, 4, 3, 7 };
    print(values, "An array");

    // all elements implicitly initialized to 0
    array<int, 4> others{};
    print(others, "A zero-initialized array");

    others.fill(-1);
    print(others, "An array filled with -1");

    for (int& cur : values) {
        cur += 1;
    }
    print(values, "An all element increase");

    cout << "First element in values: " << values.front() << endl;
    cout << "Last element in values: " << values.back() << endl;

    values.swap(others);
    print(values, "Swap arrays");
}
