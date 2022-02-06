#include <iostream>
using namespace std;

struct Point {
    // Point() {} // implicit
    // Point() = delete;
    // Point() = default;
    // Point(int test) { x = y = test; }

    int x;
    int y;
};

int main() {
    // compiler generated default ctor
    Point a;
    cout << "Risky, uninitialized point: " << a.x << ' ' << a.y << endl;
}
