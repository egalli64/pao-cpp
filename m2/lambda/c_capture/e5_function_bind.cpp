#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

namespace {
    void print(const std::vector<int>& data, const std::string& message = "") {
        std::cout << message << ": ";
        copy(data.cbegin(), data.cend(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << '\n';
    }

    void increaseValueBy(int& value, int delta) {
        value += delta;
    }

    void increaseByValue(int delta, int& value) {
        value += delta;
    }
}

int main() {
    std::vector<int> values{ 1, 2, 3 };
    print(values, "A few values");

    std::cout << "Increase by [0 .. 3) using for_each + function (placeholder 1st)\n";
    for (int i = 0; i < 3; ++i) {
        for_each(values.begin(), values.end(), std::bind(increaseValueBy, std::placeholders::_1, i));
        print(values);
    }

    std::cout << "Increase by [0 .. 3) using for_each + function (placeholder 2nd)\n";
    for (int i = 0; i < 3; ++i) {
        for_each(values.begin(), values.end(), std::bind(increaseByValue, i, std::placeholders::_1));
        print(values);
    }
}
