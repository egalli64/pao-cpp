#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
    cout << "The caller ";
    if(argc == 1)
        cout << "didn't pass any parameter\n";
    else
        cout << "passed at least a parameter\n";
}
