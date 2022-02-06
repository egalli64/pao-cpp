#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(const vector<int>& items, const string& label) {
    cout << label << " [ ";
    for (const auto& item : items) {
        cout << item << ' ';
    }
    cout << ']' << endl;
}

template<typename IT>
void square(IT first, IT last) {
    while(first != last) {
        *first = (*first) * (*first);
        ++first;
    }
}

int main() {
    vector<int> values{ 7, 3, 11 };
    print(values, "A vector");

    replace(values.begin(), values.end(), 3, 5);
    print(values, "Replaced");

    square(values.begin(), values.end());
    print(values, "Squared");
}
