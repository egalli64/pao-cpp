#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class HasSizeEqualTo
{
private:
    const size_t size_;

public:
    HasSizeEqualTo(const int size) : size_(size) {}

    bool operator()(const string& other) const {
        return other.size() == size_;
    }
};

class Concatenate
{
private:
    const string tag_;

public:
    Concatenate(const string& tag) : tag_(tag) {}

    string operator()(const string& other) const {
        return other + tag_;
    }
};

class PrintToStreamSized
{
private:
    ostream& os_;
    const size_t size_;
public:
    PrintToStreamSized(ostream& os, size_t size) : os_(os), size_(size) {}

    void operator()(const string& s) const {
        if (s.size() == size_) {
            os_ << s << ' ';
        }
    }
};

bool hasSizeEqualToFour(const string& s) {
    return s.size() == 4;
}

void printToCoutSizedThree(const string& s) {
    if (s.size() == 3) {
        cout << s << ' ';
    }
}

int main() {
    vector<string> values{ "Tom", "Kim", "Tony", "Liza" };

    cout << "Find first string sized 4: ";
    // function version
    auto it = find_if(values.begin(), values.end(), hasSizeEqualToFour);
    // functor version
    // auto it = find_if(values.begin(), values.end(), HasSizeEqualTo(4));
    // lambda version
    // auto it = find_if(values.begin(), values.end(), [](const string& x) { return x.size() == 4; });
    cout << (it != values.end() ? *it : "Not found!") << endl;

    cout << "Print all string sized 3: ";
    // function version
    // for_each(values.begin(), values.end(), printToCoutSizedThree);
    // functor version
    // for_each(values.begin(), values.end(), PrintToStreamSized(cout, 3));
    // lambda version
    for_each(values.begin(), values.end(), [](const string& s) {
        if (s.size() == 3) {
            cout << s << ' ';
        }
    });
    cout << endl;
}
