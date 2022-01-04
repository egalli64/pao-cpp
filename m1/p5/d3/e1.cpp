#include <iostream>
using namespace std;

class Player {
private:
    int id_;
    double score_;

public:
    Player(int id, double score) : id_{ id }, score_{ score } {}

    // Player(const Player &) = delete; // no copy ctor
    // Player &operator=(const Player &) = delete; // no assigment operator

    int id() { return id_; }
    double score() { return score_; }
};

int main() {
    // no compiler generated default ctor
    // Player tom;

    Player tom(12, 23.5);
    cout << "tom: " << tom.id() << ", " << tom.score() << endl;

    // compiler generated copy ctor
    Player bob = tom;
    cout << "bob: " << bob.id() << ", " << bob.score() << endl;

    Player al(0, 0);
    cout << "al: " << al.id() << ", " << al.score() << endl;

    // compiler generated assigment operator
    al = bob;
    cout << "al (after assignment): " << al.id() << ", " << al.score() << endl;
}
