#include<iostream>
#include<string>
using namespace std;

template <typename T>
void print(const T& x) {
    cout << "The value is " << x << endl;
}

int main() {
    int a{ 42 };
    print(a);

    double d{ 42.118 };
    print(d);

    string s{ "hello" };
    print(s);
}
