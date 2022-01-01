#include <iostream>
#include <memory>
#include <string>
#include <vector>
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

    virtual void sayHello() const
    {
        cout << "Hello " << value() << endl;
    }
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

class ExtendedEntry : public Entry
{
public:
    ExtendedEntry(int key, const string& value) : Entry(key, value) {}
    void sayHello() const override
    {
        cout << "Hello " << value() << "!!!" << endl;
    }
};

int main()
{
    // OK, but only if we are _not_ interested in polymorphism 
    vector<Entry> empty;
    cout << "Size of an empty vector is " << empty.size() << endl;

    vector<Entry> data{ {1, "Tom"}, {2, "Bob"} };
    print(data);

    data.push_back({ 3, "Kim" });
    print(data);

    ExtendedEntry wim{ 4, "Wim" };
    wim.sayHello();

    // BAD! Wim is sliced off !!!
    data.push_back(wim);
    for (const Entry& cur : data)
    {
        cur.sayHello();
    }
    cout << endl;

    // polymorphic container 
    vector<unique_ptr<Entry>> polyData;
    polyData.push_back(make_unique<Entry>(1, "Tom"));

    polyData.push_back(make_unique<ExtendedEntry>(2, "Bob"));
    for (const auto& cur : polyData)
    {
        cur->sayHello();
    }
    cout << endl;

    polyData[0]->sayHello();
}
