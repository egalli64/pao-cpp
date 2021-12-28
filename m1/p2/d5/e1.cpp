#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    cout << argv[0] << " has " << argc - 1 << " parameters" << endl;
    int i = 1;
    while (i < argc)
    {
        cout << i << ") " << argv[i] << endl;
        i += 1;
    }
}
