#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& data) {
    for (int cur : data) {
        cout << cur << ' ';
    }
    cout << endl;
}

int main() {
    vector<int> empty;
    cout << "Size of an empty vector is " << empty.size() << endl;

    vector<int> data{ 6, 4, 3 };
    print(data);

    // no filling in vector
    // values.fill(-1);

    // increase all the elements
    for (int& cur : data) {
        cur += 1;
    }
    print(data);
}
