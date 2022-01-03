#include <iostream>
using namespace std;

class Player
{
private:
    int id_;
    double score_;

public:
    Player(int id, double score) : id_(id), score_(score) {}

    int id() const { return id_; }
    double score() const { return score_; }
    void increaseScore(double delta) { score_ += delta; }
};

/**
 * @brief Declaring a free function that prints a player
 *
 * @param player passed by constant reference
 */
void print(const Player& player);

int main()
{
    Player tom(42, 33.12);

    // a function should be at least declared before invoked
    // the definition should be available to the executable
    print(tom);
}

/**
 * @brief Defining a free function that prints a player
 *
 * @param player passed by constant reference
 */
void print(const Player& player)
{
    cout << "The player has id " << player.id() << " and score " << player.score() << endl;
}
