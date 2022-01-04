#include <iostream>
using namespace std;

class Player {
private:
    int id_;
    double score_;

public:
    // Player() = delete; // explicitly no default ctor
    // Player() = default; // force default ctor

    // plain ctor
    Player(int id, double score) : id_{ id }, score_{ score } {}

    // dtor
    ~Player() { cout << "dtor!" << endl; }

    int id() { return id_; }
    double score() { return score_; }
};

int main() {
    // default ctor not available!
    // Player tom;

    // plain ctor
    Player bob(5, 3.8);
    cout << "bob: " << bob.id() << ", " << bob.score() << endl;
}
