#include <iostream>
using namespace std;

void print(int* data, int size) {
    for (int i = 0; i < size; ++i) {
        cout << data[i] << ' ';
    }
    cout << endl;
}

int main() {
    int sValues[]{ 6, 4, 3, 6 };

    for(size_t i = 0; i < sizeof(sValues) / sizeof(int); ++i) {
        cout << sValues[i] << ' ';
    }
    cout << endl;

    print(sValues, sizeof(sValues) / sizeof(int));

    int sValues2[]{ 3, 6 };
    print(sValues2, sizeof(sValues2) / sizeof(int));

    int* hValues = new int[3]{ 32, 12, 38 };
    print(hValues, 3);
    delete[] hValues;
}
