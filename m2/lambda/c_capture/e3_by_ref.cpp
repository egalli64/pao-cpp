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

    std::cout << "Capturing by reference (be careful with this one!)\n";
    int i = 0;
    auto risky = [&i](int& cur) { cur += i;};
    while (i < 3) {
        for_each(values.begin(), values.end(), risky);
        print(values);
        i += 1;
    }
}
