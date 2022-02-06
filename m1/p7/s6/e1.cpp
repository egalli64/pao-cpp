#include <iostream>
#include <map>
#include <string>
using namespace std;

void print(const map<string, double>& items) {
    for (const auto& item : items) {
        cout << item.first << ' ' << item.second << endl;
    }
    cout << endl;
}

int main() {
    map<string, double> data{ {"tom", 32.18}, {"bob", 44.11}, {"kim", 98.03} };
    print(data);
}
