#include<algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(const vector<string>& items, const string& label) {
    cout << label << " [ ";
    for (const auto& item : items) {
        cout << item << ' ';
    }
    cout << ']' << endl;
}

int main() {
    vector<string> data{ "tom", "bob", "kim" };
    print(data, "A string vector");
    sort(data.begin(), data.end());
    print(data, "Sorted");
}
