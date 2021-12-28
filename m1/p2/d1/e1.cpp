#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    cout << "Hello!";
    if (argc == 1)
        cout << " The caller didn't pass any argument\n";
}
