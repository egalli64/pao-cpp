#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

void print(const string& message, const vector<int>& data) {
    cout << message << ": ";
    copy(data.cbegin(), data.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

bool largerFirst(int left, int right) {
    return left > right;
}

class OddFirst {
public:
    bool operator()(int left, int right) {
        if (!(left % 2 ^ right % 2)) {
            return left < right;
        }
        return left % 2;
    }
};

int main() {
    vector<int> data{ 34, 12, 3, 8, 5, 43 };
    print("original data", data);

    sort(data.begin(), data.end());
    print("plain sort", data);

    sort(data.begin(), data.end(), largerFirst);
    print("sort by function, larger first", data);

    OddFirst of;
    sort(data.begin(), data.end(), of);
    print("sort by functor, odd and small first", data);

    sort(data.begin(), data.end(), [](int left, int right) { return left > right; });
    print("sort by lambda, larger first", data);
}
