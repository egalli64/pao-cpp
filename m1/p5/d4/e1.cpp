#include <cmath>
#include <iostream>
using namespace std;

class Player {
private:
    int id_;
    double* scores_;
    int size_;

public:
    Player(int id, int size) : id_{ id }, scores_{ new double[size] }, size_{ size } {}
    ~Player() { delete scores_; }

    // copy
    Player(const Player& other);
    Player& operator=(const Player& other);

    // move
    Player(Player&& other);
    Player& operator=(Player&& other);

    int id() { return id_; }
    void addToScore(int pos, double score) {
        int i = (pos < 0 || pos >= size_) ? 0 : pos;
        scores_[i] += score;
    }

    double score(int pos) {
        int i = (pos < 0 || pos >= size_) ? 0 : pos;
        return scores_ ? scores_[i] : NAN;
    }
};

Player::Player(const Player& other) : id_{ other.id_ }, scores_{ new double[other.size_] }, size_{ other.size_ } {
    for (int i = 0; i != size_; ++i) {
        scores_[i] = other.scores_[i];
    }
}

Player& Player::operator=(const Player& other) {
    id_ = other.id_;

    double* buffer = new double[other.size_];
    for (int i = 0; i != size_; ++i) {
        buffer[i] = other.scores_[i];
    }

    delete[] scores_;
    scores_ = buffer;
    size_ = other.size_;

    return *this;
}

Player::Player(Player&& other) : id_{ other.id_ }, scores_{ other.scores_ }, size_{ other.size_ } {
    other.id_ = 0;
    other.scores_ = nullptr;
    other.size_ = 0;
}

Player& Player::operator=(Player&& other) {
    id_ = other.id_;
    scores_ = other.scores_;
    size_ = other.size_;

    other.id_ = 0;
    other.scores_ = nullptr;
    other.size_ = 0;

    return *this;
}

int main() {
    Player tom(12, 3);
    tom.addToScore(0, 43.12);
    cout << "tom: " << tom.id() << ", " << tom.score(0) << endl;

    // copy ctor
    // the data is copied from tom to bob
    Player bob = tom;

    // bob has his own data
    bob.addToScore(0, 12.33);
    cout << "bob: " << bob.id() << ", " << bob.score(0) << endl;
    cout << "tom: " << tom.id() << ", " << tom.score(0) << endl;

    // tom is moved in al
    Player al = move(tom);
    al.addToScore(0, 1.99);
    cout << "al: " << al.id() << ", " << al.score(0) << endl;
    cout << "bob: " << bob.id() << ", " << bob.score(0) << endl;
    cout << "tom: " << tom.id() << ", " << tom.score(0) << endl;
}
