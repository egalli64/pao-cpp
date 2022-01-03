#include <iostream>
using namespace std;

struct Player
{
    int id;
    double score;
};

int main()
{
    Player tom;
    tom.id = 34;
    tom.score = 3.12;

    cout << tom.id << ' ' << tom.score << endl;

    Player* p = &tom;
    cout << p->id << endl;

    Player& r = tom;
    r.score += 5;
    cout << tom.score << endl;
}