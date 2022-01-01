#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Entry
{
private:
    int key_;
    string value_;
public:
    Entry(int key, const string& value) : key_(key), value_(value) {}

    int key() const { return key_; }
    const string& value() const { return value_; }

    void setKey(int key) { key_ = key; };
    void setValue(const string& value) { value_ = value; }
};

ostream& operator<<(ostream& os, const Entry& entry)
{
    os << '[' << entry.key() << ", " << entry.value() << ']';
    return os;
}

void print(const vector<Entry>& data)
{
    for (const Entry& cur : data)
    {
        cout << cur << ' ';
    }
    cout << endl;
}

int main()
{
    vector<Entry> empty;
    cout << "Size of an empty vector is " << empty.size() << endl;

    vector<Entry> data{ {1, "hello"}, {2, "ciao"} };
    print(data);

    data.push_back({ 3, "hola" });
    print(data);
}
