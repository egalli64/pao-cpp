#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

void print(const string& message, const vector<int>& data) {
    cout << message << ": ";
    copy(data.cbegin(), data.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main() {
    vector<int> values{ 5, 3, 21, 9, 8, 24 };
    print("A few values", values);

    cout << "Capture the values at the moment of lambda creation" << endl;
    for (int i = 0; i < 3; ++i) {
        for_each(values.begin(), values.end(), [i](int& cur) { cur += i;});
        cout << i;
        print(" ...", values);
    }

    cout << "The captured value, by default, is a copy!" << endl;
    int i = 0;
    auto wrong = [i](int& cur) { cur += i;};
    while (i < 3) {
        for_each(values.begin(), values.end(), wrong);
        cout << i;
        print(" ...", values);
        i += 1;
    }

    cout << "Capturing by reference (could be dangerous)" << endl;
    i = 0;
    auto risky = [&i](int& cur) { cur += i;};
    while (i < 3) {
        for_each(values.begin(), values.end(), risky);
        cout << i;
        print(" ...", values);
        i += 1;
    }
}
