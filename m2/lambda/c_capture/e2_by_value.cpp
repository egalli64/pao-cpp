#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

namespace {
    void print(const std::vector<int>& data, const std::string& message = "") {
        std::cout << message << ": ";
        copy(data.cbegin(), data.cend(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << '\n';
    }
}

int main() {
    std::vector<int> values{ 1, 2, 3 };
    print(values, "A few values");

    std::cout << "Increase by [0 .. 3) using for_each + lambda, capturing by value\n";
    for (int i = 0; i < 3; ++i) {
        for_each(values.begin(), values.end(), [i](int& cur) {cur += i;});
        print(values);
    }

    std::cout << "Increase always by 0! The capture is done when the lambda is created\n";
    int i = 0;
    auto wrong = [i](int& cur) { cur += i;};
    while (i < 3) {
        for_each(values.begin(), values.end(), wrong);
        print(values);
        i += 1;
    }
}
