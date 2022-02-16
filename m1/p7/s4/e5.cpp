#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

#include "ExtendedEntry.h"

int main() {
    cout << "Raw Pointer Vector" << endl;
    vector<Entry*> values{ new Entry(1, "Tom"), new Entry(2, "Bob") };
    values.push_back(new Entry(3, "Kim"));
    values.push_back(new ExtendedEntry(4, "Wim", "!!!"));
    for (const Entry* cur : values) {
        cur->sayHello();
    }
    cout << "Access to an element in vector: ";
    values[0]->sayHello();

    ExtendedEntry* ee = dynamic_cast<ExtendedEntry*>(values[values.size() - 1]);
    if (ee) {
        cout << "Last element is extended: " << *ee << endl;
    }
    else {
        cout << "You should not see this line" << endl;
    }

    cout << "Before vector goes out of scope, a handmade cleanup is required!" << endl;
    for (Entry* cur : values) {
        delete cur;
    }

    // a clear is not actually required here, the vector is about to be destroyed
    cout << "Size is still " << values.size() << endl;
    values.clear();
    cout << "Now size is " << values.size() << endl;
}
