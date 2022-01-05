#include <iostream>
using namespace std;

class Point {
private:
    int x_;
    const int y_;

public:
    Point() : x_{ 0 }, y_{ 0 } {} // the default ctor
    explicit Point(int x) : x_{ x }, y_{ 0 } {} // a plain explicit ctor
    Point(int x, int y) : x_{ x }, y_{ y } {} // another plain ctor
    ~Point() { cout << "dtor " << x_ << ' ' << y_ << endl; } // the dtor

    int x() { return x_; }
    int y() { return y_; }
    void increaseX(int delta) { x_ += delta; }
};

int main() {
    // default ctor
    Point a;
    cout << "a is " << a.x() << ' ' << a.y() << endl;

    Point b{};
    cout << "b is " << b.x() << ' ' << b.y() << endl;

    // plain ctors
    Point c(3, 4);
    cout << "c is " << c.x() << ' ' << c.y() << endl;

    Point d{ 5, 6 };
    d.increaseX(3);
    cout << "d is " << d.x() << ' ' << d.y() << endl;

    // can't see the explicit constructor
    // Point e = 42;

    Point e{ 42 };
    cout << "e is " << e.x() << ' ' << e.y() << endl;

    Point f = static_cast<Point>(7);
    cout << "f is " << f.x() << ' ' << f.y() << endl;
}
