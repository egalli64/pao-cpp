#include <iostream>
using namespace std;

/**
 * @brief A more structured class
 */
class Point {
private:
    int x_;
    int y_;

public:
    Point(int x, int y) : x_(x), y_(y) {}

    int x() { return x_; }
    int y() { return y_; }
    void increaseX(int delta) { x_ += delta; }
};

int main() {
    Point a {34, 3};
    cout << a.x() << ' ' << a.y() << endl;

    Point* p = &a;
    cout << p->x() << ' ' << p->y() << endl;

    Point& r = a;
    r.increaseX(5);
    cout << a.x() << ' ' << a.y() << endl;
}
