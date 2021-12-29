#include <iostream>
using namespace std;

class Player
{
private:
    int id_;
    double score_;

public:
    Player() : id_{ 0 }, score_{ 0 } {} // default ctor
    Player(int id, double score) : id_{ id }, score_{ score } {}    // plain ctor
    ~Player() { cout << "dtor!" << endl; }  // dtor

    int id() { return id_; }
    double score() { return score_; }
};

main()
{
    // default ctor
    Player tom;
    cout << "tom: " << tom.id() << ", " << tom.score() << endl;

    // plain ctor
    Player bob(5, 3.8);
    cout << "bob: " << bob.id() << ", " << bob.score() << endl;
}