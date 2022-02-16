#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

#include "ExtendedEntry.h"

int main() {
    cout << "*** Unique Smart Pointer Vector" << endl;
    // unique_ptr is not copiable, as required by initializer_list, so, can't be used here
    vector<unique_ptr<Entry>> values;
    values.push_back(make_unique<Entry>(1, "Tom"));
    values.push_back(make_unique<Entry>(2, "Bob"));
    values.push_back(make_unique<Entry>(3, "Kim"));
    values.push_back(make_unique<ExtendedEntry>(4, "Wim", "!!!"));

    cout << "*** All entries say hello" << endl;
    for (const auto& cur : values) {
        cur->sayHello();
    }

    cout << "*** Vector is about to going out of scope" << endl;
}
