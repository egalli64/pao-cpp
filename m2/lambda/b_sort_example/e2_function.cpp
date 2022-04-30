#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

void print(const std::string& message, const std::vector<int>& data) {
    std::cout << message << ": ";
    copy(data.cbegin(), data.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}

bool largerFirst(int left, int right) {
    return left > right;
}

int main() {
    std::vector<int> data{ 34, 12, 3, 8, 5, 43 };
    print("original data", data);

    std::sort(data.begin(), data.end());
    print("plain sort", data);

    std::sort(data.begin(), data.end(), largerFirst);
    print("sort by function, larger first", data);
}
