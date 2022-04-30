#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

void print(const std::string& message, const std::vector<int>& data) {
    std::cout << message << ": ";
    copy(data.cbegin(), data.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}

int main() {
    std::vector<int> data{ 34, 12, 3, 8, 5, 43 };
    print("original data", data);

    std::sort(data.begin(), data.end(), [](int left, int right) { return left > right; });
    print("reversed sort by lambda", data);
}
