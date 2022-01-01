#include <iostream>
using namespace std;

void print(int* data, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << ' ';
    }
    cout << endl;
}

int main()
{
    int sValues[]{ 6, 4, 3 };
    print(sValues, 3);

    int* hValues = new int[3]{ 32, 12, 38 };
    print(hValues, 3);
    delete[] hValues;
}
