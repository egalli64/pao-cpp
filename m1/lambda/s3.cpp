#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

void print(const string& message, const vector<int>& data) {
    cout << message << ": ";
    copy(data.cbegin(), data.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void increaseByOne(int& value) {
    value += 1;
}

void increase(int& value, int delta) {
    value += delta;
}

int main() {
    vector<int> values{ 1, 2, 3, 4, 5 };
    print("A few values", values);

    cout << "Increase by 1 using for_each + function" << endl;
    for (int i = 0; i < 3; ++i) {
        for_each(values.begin(), values.end(), increaseByOne);
        cout << i;
        print(" ...", values);
    }

    cout << "Increase by [0 .. 3) using for_each + lambda, capturing by value" << endl;
    for (int i = 0; i < 3; ++i) {
        for_each(values.begin(), values.end(), [i](int& cur) { cur += i;});
        cout << i;
        print(" ...", values);
    }

    cout << "Increase always by 0! The capture is done when the lambda is created" << endl;
    int i = 0;
    auto wrong = [i](int& cur) { cur += i;};
    while (i < 3) {
        for_each(values.begin(), values.end(), wrong);
        cout << i;
        print(" ...", values);
        i += 1;
    }

    cout << "Capturing by reference (be careful with this one!)" << endl;
    i = 0;
    auto risky = [&i](int& cur) { cur += i;};
    while (i < 3) {
        for_each(values.begin(), values.end(), risky);
        cout << i;
        print(" ...", values);
        i += 1;
    }
    
    cout << "(Spoiler: using for_each + bind to increase by an adapted function)" << endl;
    for (int i = 0; i < 3; ++i) {
        for_each(values.begin(), values.end(), bind(increase, std::placeholders::_1, i));
        cout << i;
        print(" ...", values);
    }
}