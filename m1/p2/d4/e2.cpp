#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

const int MAX_VALUE = 6;

int dieCast() {
    return rand() % MAX_VALUE + 1;
}

int main() {
    srand(time(0));

    cout << "How many times? ";
    int size;
    cin >> size;

    int scores[MAX_VALUE * 2 + 1]{ 0 };
    int* casts = new int[size];
    for (int i = 0; i < size; ++i) {
        casts[i] = dieCast() + dieCast();
        scores[casts[i]] += 1;
        cout << casts[i] << ' ';
    }

    cout << "\n\nDistribution" << endl;
    for (int i = 2; i < MAX_VALUE * 2 + 1; ++i) {
        cout << '[' << i << ": " << static_cast<double>(scores[i]) / size << ']';
    }
    cout << endl;
    delete[] casts;
}
