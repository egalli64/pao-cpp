#include<iostream>
using namespace std;

int main(int argc, char** argv) {
    switch(argc) {
    case 1:
        cout << "The caller didn't pass any parameter\n";
        break;
    case 2:
        cout << "The first parameter is " << argv[1] << endl;
        break;
    default:
        cout << "The last parameter is " << argv[argc-1] << endl;
        break;
    }
}
