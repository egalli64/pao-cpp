#include <iostream>
#include <string>
using namespace std;

class Player {
private:
    static const int SZ = 5;
    int id_;
    int* hand_;

public:
    Player(int id) : id_(id) {
        hand_ = new int[SZ];
        for (int i = 0; i < SZ; ++i) {
            hand_[i] = rand() % 10;
        }
        cout << "Ctor (new + loop) " << id_ << endl;
    }

    ~Player() {
        delete[] hand_;
        cout << "Dtor " << id_ << endl;
    }

    Player(const Player& other) {
        id_ = other.id_;
        hand_ = new int[SZ];
        for (int i = 0; i < SZ; ++i) {
            hand_[i] = other.hand_[i];
        }

        cout << "Copy ctor (new + loop) " << id_ << endl;
    }

    Player& operator=(const Player& other) {
        id_ = other.id_;

        // hand size is fixed, no need to delete
        for (int i = 0; i < SZ; ++i) {
            hand_[i] = other.hand_[i];
        }

        cout << "Assigment (loop) " << id_ << endl;
        return *this;
    }

    Player(Player&& other) {
        id_ = other.id_;
        hand_ = other.hand_;

        other.id_ = 0;
        other.hand_ = nullptr;
        cout << "Move ctor (cheap!): " << id_ << endl;
    }

    Player& operator=(Player&& other) {
        id_ = other.id_;

        delete[] hand_;
        hand_ = other.hand_;

        other.id_ = 0;
        other.hand_ = nullptr;

        cout << "Move assigment (cheap!): " << id_ << endl;
        return *this;
    }

    void print() const {
        cout << id_ << ": [ ";
        for (int i = 0; i < SZ; ++i) {
            cout << hand_[i] << ' ';
        }
        cout << ']' << endl;
    }
};

void swapCopy(Player& left, Player& right) {
    cout << "Swap by copy" << endl;

    Player buffer = left;
    left = right;
    right = buffer;
}

void swapMove(Player& left, Player& right) {
    cout << "Swap by move" << endl;

    Player buffer = move(left);
    left = move(right);
    right = move(buffer);
}

int main() {
    Player p1(1);
    Player p2(2);

    p1.print();
    p2.print();

    swapCopy(p1, p2);

    p1.print();
    p2.print();
    
    swapMove(p1, p2);

    p1.print();
    p2.print();
}
