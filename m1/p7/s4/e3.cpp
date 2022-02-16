#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> values;
    cout << "Empty vector" << endl;
    cout << "Size is " << values.size() << endl;
    cout << "Capacity is " << values.capacity() << endl;

    values.push_back(2); // fast
    values.emplace_back(42); // usually fastest
    values.insert(values.begin(), 12); // could be very slow

    cout << "Size is " << values.size() << endl;
    cout << "Capacity is " << values.capacity() << endl;
    cout << "First element is " << values.front() << endl;
    cout << "Last element is " << values.back() << endl;
}
