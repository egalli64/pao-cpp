#include <iostream>
using namespace std;

void swap(int& left, int& right) {
    cout << "swapping integers" << endl;
    int temp = left;
    left = right;
    right = temp;
}

void swap(double& left, double& right) {
    cout << "swapping doubles" << endl;
    double temp = left;
    left = right;
    right = temp;
}

int main() {
    int a{ 42 };
    int b{ 18 };

    cout << "a is " << a << " b is " << b << endl;
    swap(a, b);
    cout << "a is " << a << " b is " << b << endl;

    double d{ 42.82 };
    double e{ 18.09 };

    cout << "d is " << d << " e is " << e << endl;
    swap(d, e);
    cout << "d is " << d << " e is " << e << endl;
}
