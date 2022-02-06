#include <iostream>
#include <string>
using namespace std;

class Point {
    friend ostream& operator<<(ostream& os, const Point& point);
private:
    int x_;
    int y_;
    const string label_;

public:
    Point(int x, int y, const string& label) : x_(x), y_(y), label_(label) {}

    int x() const { return x_; }
    int y() const { return y_; }

    void horMove(int delta) { x_ += delta; }
    void vertMove(int delta) { y_ += delta; }

    ostream& write(ostream& os) const {
        return os << label_ << ": " << x_ << ", " << y_;
    }

    operator string() const {
        return label_ + ": " + to_string(x_) + ", " + to_string(y_);
    }
};

ostream& operator<<(ostream& os, const Point& point) {
    return os << point.label_ << ": " << point.x_ << ", " << point.y_;

    // alternative approaches, no friendship required
    // return point.write(os);
    // return os << static_cast<string>(point);
}

int main() {
    Point a{ 12, 5, "A" };

    cout << "Operator <<() --> ";
    cout << a << endl;

    cout << "Operator string() --> ";
    cout << static_cast<string>(a) << endl;

    cout << "Method write() --> ";
    a.write(cout) << endl;
}
