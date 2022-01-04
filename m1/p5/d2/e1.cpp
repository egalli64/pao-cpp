#include <iostream>
using namespace std;

struct Player {
    // Player() {} // implicit
    // Player() = delete;
    // Player() = default;
    int id;
    double score;
};

int main() {
    // compiler generated default ctor
    Player tom;
    cout << "tom: " << tom.id << ", " << tom.score << endl;
}
