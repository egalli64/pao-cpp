#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
    cout << "The caller ";
    if(argc == 1)
        cout << "didn't pass any parameter\n";
    else if(argc == 2)
        cout << "passed a parameter: " << argv[1] << endl;
    else if(argc % 2)
        cout << "passed an even number of parameters\n";
    else
        cout << "passed an odd number of parameters\n";
}
