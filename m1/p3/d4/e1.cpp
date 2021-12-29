#include<cmath>
#include <iostream>
using namespace std;

class Player
{
private:
    int id_;
    double* scores_;
    int size_;

public:
    Player(int id, int size) : id_{ id }, scores_{ new double[size] }, size_{ size } {}
    ~Player() { delete scores_; }

    // copy
    Player(const Player& that);
    Player& operator=(const Player& that);

    // move
    Player(Player&& that);
    Player& operator=(Player&& that);

    int id() { return id_; }
    void add_score(int pos, double score)
    {
        int i = (pos < 0 || pos >= size_) ? 0 : pos;
        scores_[i] += score;
    }

    double score(int pos)
    {
        int i = (pos < 0 || pos >= size_) ? 0 : pos;
        return scores_ ? scores_[i] : NAN;
    }
};

Player::Player(const Player& that) :
    id_{ that.id_ }, scores_{ new double[that.size_] }, size_{ that.size_ }
{
    for (int i = 0; i != size_; ++i)
        scores_[i] = that.scores_[i];
}

Player& Player::operator=(const Player& that)
{
    id_ = that.id_;

    double* buffer = new double[that.size_];
    for (int i = 0; i != size_; ++i)
        buffer[i] = that.scores_[i];

    delete[] scores_;
    scores_ = buffer;
    size_ = that.size_;

    return *this;
}

Player::Player(Player&& that) :
    id_{ that.id_ }, scores_{ that.scores_ }, size_{ that.size_ }
{
    that.id_ = 0;
    that.scores_ = nullptr;
    that.size_ = 0;
}

Player& Player::operator=(Player&& that)
{
    id_ = that.id_;
    scores_ = that.scores_;
    size_ = that.size_;

    that.id_ = 0;
    that.scores_ = nullptr;
    that.size_ = 0;

    return *this;
}

int main()
{
    Player tom(12, 3);
    tom.add_score(0, 43.12);
    cout << "tom: " << tom.id() << ", " << tom.score(0) << endl;

    // copy ctor
    // the data is copied from tom to bob
    Player bob = tom;

    // bob has his own data
    bob.add_score(0, 12.33);
    cout << "bob: " << bob.id() << ", " << bob.score(0) << endl;
    cout << "tom: " << tom.id() << ", " << tom.score(0) << endl;

    // tom is moved in al
    Player al = move(tom);
    al.add_score(0, 1.99);
    cout << "al: " << al.id() << ", " << al.score(0) << endl;
    cout << "bob: " << bob.id() << ", " << bob.score(0) << endl;
    cout << "tom: " << tom.id() << ", " << tom.score(0) << endl;
}