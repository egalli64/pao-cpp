#include <iostream>
using namespace std;

class Player {
private:
    static int count_;
    int id_;
    double score_;

public:
    Player(int id, double score) : id_(id), score_(score) { count_ += 1; }
    ~Player() { count_ -= 1; }

    int id() const { return id_; }
    double score() const { return score_; }
    void increaseScore(double delta) { score_ += delta; }

    static void printCount();
};

int Player::count_ = 0;

void Player::printCount() {
    cout << "Current number of players: " << count_ << endl;
}

void another_function() {
    Player bob(12, 3.7);
    Player::printCount();
}

int main() {
    Player::printCount();

    Player tom(42, 33.12);
    Player::printCount();
    tom.printCount(); // a bit confusing: is it an instance method?

    another_function();
    Player::printCount();
}
