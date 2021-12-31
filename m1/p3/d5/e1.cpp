#include <iostream>
#include <memory>
using namespace std;

class Player
{
private:
    int id_;
    double score_;

public:
    Player(int id, double score) : id_(id), score_(score) {}
    ~Player()
    {
        cout << "dtor" << endl;
    }

    int id() { return id_; }
    double score() { return score_; }
    void increaseScore(double delta) { score_ += delta; }
};

int main()
{
    Player* p = new Player(12, 3.45);
    p->increaseScore(23.3);
    cout << p->id() << ' ' << p->score() << endl;
    delete p;

    auto tom = make_unique<Player>(12, 3.45);
    p->increaseScore(23.3);
    cout << tom->id() << ' ' << tom->score() << endl;
}