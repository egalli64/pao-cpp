#include<algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(const vector<string>& items)
{
    cout << "[ ";
    for (const auto& item : items)
    {
        cout << item << ' ';
    }
    cout << ']' << endl;
}

int main()
{
    vector<string> data{ "tom", "bob", "kim" };
    print(data);
    sort(data.begin(), data.end());
    print(data);

    string target{ "tom" };
    auto itTom = find(data.begin(), data.end(), target);
    cout << target << (itTom == data.end() ? " not " : " ") << "found" << endl;
}
