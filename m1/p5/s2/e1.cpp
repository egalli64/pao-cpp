#include <iostream>
using namespace std;

/**
 * @brief A simple class
 */
struct Point {
    int x;
    int y;
};

int main() {
    Point a{ 5,7 };
    cout << a.x << ' ' << a.y << endl;

    Point* p = &a;
    cout << p->x << ' ' << p->y << endl;

    Point& r = a;
    r.x += 5;
    cout << r.x << ' ' << r.y << endl;

    // !!! not initialized !!!
    Point b;
    cout << b.x << ' ' << b.y << endl;
}
