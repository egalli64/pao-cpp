#include <iostream>
using namespace std;

class Point {
private:
    int x_;
    int y_;

public:
    Point(int x, int y) : x_{ x }, y_{ y } {}
    ~Point() { cout << "dtor " << x_ << ", " << y_ << endl; }

    // Point(const Point&) = delete; // no copy ctor
    // Point& operator=(const Point&) = delete; // no assigment operator

    int x() { return x_; }
    int y() { return y_; }
    void horizontalMove(int delta) { x_ += delta; }
};

int main() {
    // no compiler generated default ctor
    // Point a;

    Point b{ 12, 23 };
    cout << "b: " << b.x() << ", " << b.y() << endl;

    // compiler generated copy ctor
    Point c = b;
    c.horizontalMove(12);

    Point d{ b };
    d.horizontalMove(-7);

    cout << "c is a deep copy _by copy ctor_ of b (right shifted): " << c.x() << ", " << c.y() << endl;
    cout << "d is a deep copy _by copy ctor_ of b (left shifted): " << d.x() << ", " << d.y() << endl;
    cout << "b has not changed: " << b.x() << ", " << b.y() << endl;

    // compiler generated assigment operator
    d = c;
    d.horizontalMove(-4);
    cout << "d is a deep copy _by assignment_ of c (left shifted): " << d.x() << ", " << d.y() << endl;
    cout << "c has not changed: " << c.x() << ", " << c.y() << endl;

    Point& e = b;
    e.horizontalMove(-2);
    cout << "e is a shallow copy _by reference_ of b (left shifted): " << e.x() << ", " << e.y() << endl;
    cout << "b HAS changed: " << b.x() << ", " << b.y() << endl;
}
