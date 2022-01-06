#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

const int MAX_VALUE = 6;

int dieCast() {
    return rand() % MAX_VALUE + 1;
}

double avg(int* values, int size) {
    double result = 0;
    for (int i = 0; i < size; ++i) {
        result += values[i];
    }
    return result / size;
}

int main() {
    srand(time(0));

    cout << "How many times? ";
    int size;
    cin >> size;

    if (size < 1 || size > 100'000'000) {
        cout << "Please, insert a reasonable value" << endl;
        return 0;
    }

    int scores[MAX_VALUE * 2 + 1]{ };
    int* casts = new int[size];
    for (int i = 0; i < size; ++i) {
        casts[i] = dieCast() + dieCast();
        scores[casts[i]] += 1;
        cout << casts[i] << ' ';
    }
    cout << "\n\nAverage: " << avg(casts, size) << endl;

    // not used anymore
    delete[] casts;

    cout << "Distribution" << endl;
    for (int i = 2; i < MAX_VALUE * 2 + 1; ++i) {
        cout << '[' << i << ": " << static_cast<double>(scores[i]) / size << ']';
    }
    cout << endl;
}
