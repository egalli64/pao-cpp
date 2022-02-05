#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    srand(time(nullptr));

    do {
        int aRandomValue = rand() % 100; // [0..99]
        cout << aRandomValue << ' ';

        if (aRandomValue > 66) {
            break;
        }
    } while (true);

    cout << "Done!" << endl;
}
