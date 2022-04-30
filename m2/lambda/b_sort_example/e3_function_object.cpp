#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

void print(const std::string& message, const std::vector<int>& data) {
    std::cout << message << ": ";
    copy(data.cbegin(), data.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}

class OddFirst {
private:
    bool natural_;
public:
    OddFirst(bool odd) : natural_(odd) {
        std::cout << "Odd first " << (natural_ ? "natural" : "inverse") << '\n';
    }

    bool operator()(int left, int right) {
        if (!(left % 2 ^ right % 2)) {
            bool result = left < right;
            return natural_ ? result : !result;
        }
        return left % 2;
    }
};

int main() {
    std::vector<int> data{ 34, 12, 3, 8, 5, 43 };
    print("original data", data);

    std::sort(data.begin(), data.end(), OddFirst(true));
    print("OddFirst/natural sort", data);

    std::sort(data.begin(), data.end(), OddFirst(false));
    print("OddFirst/inverted sort", data);
}
