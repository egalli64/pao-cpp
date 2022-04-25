#include <exception>
#include <iostream>
using namespace std;

class MyException : public exception {
public:
    const char* what() const noexcept override {
        return "Something bad happened";
    }
};

void risky() {
    throw MyException();
}


int main() {
    try {
        risky();
    }
    catch (exception& me) {
        cout << me.what() << endl;
    }

    cout << "Bye" << endl;
}
