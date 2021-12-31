#include <iostream>
using namespace std;

class Player
{
private:
    int id_;
    double score_;

public:
    Player(int id, double score) : id_(id), score_(score) {}

    int id() { return id_; }
    double score() { return score_; }
    void increaseScore(double delta) { score_ += delta; }
};

int main()
{
    Player tom(34, 3.12);

    cout << tom.id() << ' ' << tom.score() << endl;

    Player* p = &tom;
    cout << p->id() << endl;

    Player& r = tom;
    r.increaseScore(5);
    cout << tom.score() << endl;
}
