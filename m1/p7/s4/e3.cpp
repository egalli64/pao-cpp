#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Entry {
private:
    int key_;
    string value_;
public:
    Entry(int key, const string& value) : key_(key), value_(value) {
        cout << "Plain ctor for " << value_ << endl;
    }

    Entry(const Entry& other) : key_(other.key_), value_(other.value_) {
        cout << "Copy ctor for " << value_ << endl;
    }

    Entry(Entry&& other) {
        cout << "Move ctor for " << other.value_ << endl;

        key_ = exchange(other.key_, 0);
        value_ = move(other.value_);
    }

    Entry& operator=(Entry&& other) {
        cout << "Move assigment for " << other.value_ << endl;

        key_ = exchange(other.key_, 0);
        value_ = move(other.value_);
        return *this;
    }

    int key() const { return key_; }
    const string& value() const { return value_; }

    void setKey(int key) { key_ = key; };
    void setValue(const string& value) { value_ = value; }

    virtual void sayHello() const {
        cout << "Hello " << value() << endl;
    }

    virtual ~Entry() { cout << "dtor " << key_ << ' ' << value_ << endl; }
};

ostream& operator<<(ostream& os, const Entry& entry) {
    return os << '[' << entry.key() << ", " << entry.value() << ']';
}

class ExtendedEntry : public Entry {
public:
    ExtendedEntry(int key, const string& value) : Entry(key, value) {
        cout << "EE plain ctor for " << value << endl;
    }

    void sayHello() const override {
        cout << "EE hello " << value() << "!!!" << endl;
    }

    virtual ~ExtendedEntry() {
        cout << "EE dtor " << value() << endl;
    }
};

void aVector() {
    vector<int> values;
    cout << "Empty vector" << endl;
    cout << "Size is " << values.size() << endl;
    cout << "Capacity is " << values.capacity() << endl;

    values.push_back(2);
    values.push_back(12);
    values.emplace_back(42);
    cout << "Size is " << values.size() << endl;
    cout << "Capacity is " << values.capacity() << endl;
    cout << "First element is " << values.front() << endl;
    cout << "Last element is " << values.back() << endl;
}

void oVector() {
    cout << "Statically typed vector - no polymorphism!" << endl;
    vector<Entry> values{ {1, "Tom"}, {2, "Bob"} };
    for (const Entry& cur : values) {
        cout << cur << ' ';
    }
    cout << endl;

    values.push_back({ 3, "Kim" });
    values.emplace_back(4, "Obi");

    ExtendedEntry wim{ 5, "Wim" };
    wim.sayHello();

    // BAD! Wim is sliced off !!!
    values.push_back(wim);
    for (const Entry& cur : values) {
        cur.sayHello();
    }
    cout << "Vector out of scope" << endl;
}

void rpVector() {
    cout << "Raw Pointer Vector" << endl;
    vector<Entry*> values{ new Entry(1, "Tom"), new Entry(2, "Bob") };
    values.push_back(new Entry(3, "Kim"));

    values.push_back(new ExtendedEntry(4, "Wim"));
    for (const auto& cur : values) {
        cur->sayHello();
    }
    cout << "Access to an element in vector: ";
    values[0]->sayHello();

    cout << "Vector out of scope, handmade cleanup!" << endl;
    for (auto& cur : values) {
        delete cur;
    }
    values.clear(); // paranoic
}

void spVector() {
    cout << "Shared Smart Pointer Vector" << endl;
    vector<shared_ptr<Entry>> values{ make_shared<Entry>(1, "Tom"), make_shared<Entry>(2, "Bob") };
    values.push_back(make_shared<Entry>(3, "Kim"));

    values.push_back(make_shared<ExtendedEntry>(4, "Wim"));
    for (const auto& cur : values) {
        cur->sayHello();
    }
    cout << "Access to an element in vector: ";
    values[0]->sayHello();
    cout << "Vector out of scope" << endl;
}

void upVector() {
    cout << "Unique Smart Pointer Vector" << endl;
    vector<unique_ptr<Entry>> values;
    values.push_back(make_unique<Entry>(1, "Tom"));
    values.push_back(make_unique<Entry>(2, "Bob"));
    values.push_back(make_unique<Entry>(3, "Kim"));

    values.push_back(make_unique<ExtendedEntry>(4, "Wim"));
    for (const auto& cur : values) {
        cur->sayHello();
    }
    cout << "Access to an element in vector: ";
    values[0]->sayHello();
    cout << "Data out of scope" << endl;
}

int main() {
    aVector();
    cout << endl << endl;
    oVector();
    cout << endl << endl;
    rpVector();
    cout << endl << endl;
    spVector();
    cout << endl << endl;
    upVector();
}
