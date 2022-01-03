#include <iostream>
#include <array>
using namespace std;

void print(const array<int, 4>& data)
{
    for (int cur : data)
    {
        cout << cur << ' ';
    }
    cout << endl;
}

int main()
{
    array<int, 3> uninitialized;
    for (int i = 0; i < uninitialized.size(); i++)
    {
        cout << uninitialized[i] << ' ';
    }
    cout << endl;

    // last element implicitly initialized to 0
    array<int, 4> data{ 6, 4, 3 };
    print(data);

    // all elements implicitly initialized to 0
    array<int, 4> values{};
    print(values);

    // filling the array with -1
    values.fill(-1);
    print(values);

    // increase all the elements
    for (int& cur : data)
    {
        cur += 1;
    }
    print(data);
}
