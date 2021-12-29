#include <iostream>
using namespace std;

int main()
{
    char c = 'x';
    char* pc = new char;
    *pc = 'z';
    cout << c << ' ' << *pc << endl;
    delete pc;

    int data[6] = { 1,2,3,4,5,6 };
    int* p_data = new int[6];
    p_data[0] = 42;
    p_data[5] = 3;
    cout << data[0] << ' ' << p_data[0] << endl;
    delete[] p_data;

    cout << "done" << endl;
}
