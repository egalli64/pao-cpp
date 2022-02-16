#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

#include "ExtendedEntry.h"

int main() {
    cout << "Statically typed vector - no polymorphism!" << endl;
    vector<Entry> values{ {1, "Tom"}, {2, "Bob"} };

    cout << "*** values: ";
    for (const Entry& cur : values) {
        cout << cur << ' ';
    }
    cout << endl;

    cout << "*** Kim is pushed back into the vector" << endl;
    values.push_back({ 3, "Kim" });
    cout << "*** Obi is emplaced into the vector" << endl;
    values.emplace_back(4, "Obi");

    cout << "*** Wim is defined and then says hello" << endl;

    {
        ExtendedEntry wim{ 5, "Wim", "!!!" };
        wim.sayHello();

        // BAD! Wim is sliced off !!!
        cout << "*** Wim is pushed back into the vector" << endl;
        values.push_back(wim);

        cout << "*** The original Wim is about to go out of scope" << endl;
    }

    cout << "*** Everyone say hello (as Entry!)" << endl;
    for (const Entry& cur : values) {
        cur.sayHello();
    }

    ExtendedEntry* ee = dynamic_cast<ExtendedEntry*>(&values[4]);
    if (ee == nullptr) {
        cout << "*** Wim is not seen as an ExtendedEntry anymore!" << endl;
    }
    else {
        cout << "You should not see this line" << endl;
    }

    cout << "*** values is about to go out of scope" << endl;
}
