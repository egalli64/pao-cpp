#include <iostream>
using namespace std;

void unsafeHello(char* name) {
    cout << "Hello " << name << '!' << endl;
    name[0] += 1;
}

void saferHello(const char* name) {
    cout << "Hello " << name << '!' << endl;
    //    name[0] += 1; // can't change!
}

int main() {
    char bob[]{ "Bob" };
    unsafeHello(bob);
    cout << "Bob now is " << bob << endl;

    char tom[]{ "Tom" };
    saferHello(tom);
}
