#include <iostream>
#include <string>
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
    vector<int> empty;
    cout << "Size of an empty vector is " << empty.size() << endl;

    vector<int> anotherEmpty{ };
    cout << "Size of another empty vector is " << empty.size() << endl;

    vector<int> filled(5, -1);
    print(filled, "A vector filled with a given value");

    // no filling for vector
    // values.fill(-1);

    vector<int> given{ 6, 4, 3 };
    print(given, "A vector with a few given values");

    vector<string> sv{ "hello" };
    print(sv, "A string vector");

    // increase all the elements
    for (int& cur : given) {
        cur += 1;
    }
    print(given, "Increased values");
}
