#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << argv[0] << " has no parameters" << endl;
    }
    else
    {
        cout << "The parameters:" << endl;
        int i = 1;
        do
        {
            cout << i << ") " << argv[i] << endl;
            i += 1;
        } while (i < argc);
    }
}
