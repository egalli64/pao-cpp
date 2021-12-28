#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "Please, enter a few arguments" << endl;
    }
    else
    {
        cout << "Arguments NOT starting with an 'x'" << endl;
        for (int i = 1; i < argc; i++)
        {
            if (argv[i][0] == 'x')
                continue;
            cout << i << ") " << argv[i] << endl;
        }
        cout << "Done" << endl;
    }
}
