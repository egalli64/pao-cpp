#include <iostream>
using namespace std;

class Player
{
private:
    int id_;
    double score_;

public:
    Player(int id, double score) : id_(id), score_(score) {}

    // implicit inline
    int id() const { return id_; }
    double score() const { return score_; }

    void increaseScore(double delta);
};

inline void Player::increaseScore(double delta)
{
    score_ += delta;
}

inline void print(const Player& player)
{
    cout << "The player has id " << player.id() << " and score " << player.score() << endl;
}

int main()
{
    Player tom(42, 33.12);
    tom.increaseScore(3.3);

    print(tom);
}
