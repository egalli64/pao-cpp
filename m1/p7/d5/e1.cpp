#include<algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int raw[]{ 5, 6, 42 };
    for (int value : raw) {
        cout << value << ' ';
    }
    cout << endl;

    for (int* ptr = raw; ptr != raw + (sizeof(raw) / sizeof(int)); ++ptr) {
        cout << *ptr << ' ';
    }
    cout << endl;

    vector<string> values{ "tom", "bob", "kim" };
    for (const auto& value : values) {
        cout << value << ' ';
    }
    cout << endl;

    for (auto it = values.cbegin(); it != values.cend(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}
