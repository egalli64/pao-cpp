#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> values{ 7, 2, 12 };

    int target{ 2 };
    auto itTwo = find(values.begin(), values.end(), target);
    cout << target << (itTwo == values.end() ? " not " : " ") << "found" << endl;

    int sum = accumulate(values.begin(), values.end(), 0);
    cout << "Sum of values is " << sum << endl;
}
