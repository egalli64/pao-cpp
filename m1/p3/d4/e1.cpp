#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    cout << argv[0] << " has " << argc - 1 << " parameters" << endl;
    for (int i = 1; i < argc; ++i) {
        cout << i << ") " << argv[i] << endl;
    }
}
