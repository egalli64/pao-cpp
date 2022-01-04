#include<iostream>
#include<string>
using namespace std;

template <typename T>
T sum(T* values, int size) {
    T result{};

    for (int i = 0; i < size; ++i) {
        result += values[i];
    }

    return result;
}

template <>
string sum(string* values, int size) {
    string result{};

    for (int i = 0; i < size - 1; ++i) {
        result += values[i];
        result.append(", ");
    }
    result += values[size - 1];

    return result;
}

int main() {
    int a[]{ 42, 12, 27 };
    cout << "Int sum is " << sum(a, 3) << endl;

    double d[]{ 42.23, 12.84, 27.22 };
    cout << "Double sum is " << sum(d, 3) << endl;

    string s[]{ "hello", "ciao", "hola" };
    cout << "String sum is " << sum(s, 3) << endl;
}
