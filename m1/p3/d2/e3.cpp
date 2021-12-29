#include <iostream>
using namespace std;

class Player
{
private:
    int id_;
    double score_;

public:
    // Player() = delete; // explicitly no default ctor
    // Player() = default; // force default ctor
    Player(int id, double score) : id_{id}, score_{score} {} // plain ctor
    ~Player() { cout << "dtor!" << endl; }                   // dtor

    int id() { return id_; }
    double score() { return score_; }
};

main()
{
    // default ctor not available!
    // Player tom;

    // plain ctor
    Player bob(5, 3.8);
    cout << "bob: " << bob.id() << ", " << bob.score() << endl;
}