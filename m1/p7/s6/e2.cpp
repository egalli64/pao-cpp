#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

void print(const unordered_map<string, double>& items) {
    for (const auto& item : items) {
        cout << item.first << ' ' << item.second << endl;
    }
    cout << endl;
}

int main() {
    unordered_map<string, double> data{ {"tom", 32.18}, {"bob", 44.11}, {"kim", 98.03} };
    data.insert({"mia", 91.12});
    data.emplace("jim", 12.23);
    print(data);
    
    auto it = data.find("bob");
    if (it != data.end()) {
        cout << "find bob: " << it->second << endl;
    }

    cout << "at tom: " << data.at("tom") << endl;

    try {
        double joe = data.at("joe");
        cout << joe << endl;
    }
    catch (const out_of_range& ex) {
        cout << "Out of range calling " << ex.what() << " on joe" << endl;
    }

}
