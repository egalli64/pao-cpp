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

    Entry(const Entry& that) : key_(that.key_), value_(that.value_) {
        cout << "Copy ctor for " << value_ << endl;
    }

    Entry(Entry&& that) {
        cout << "Move ctor for " << that.value_ << endl;

        key_ = exchange(that.key_, 0);
        value_ = move(that.value_);
    }

    Entry& operator=(Entry&& that) {
        cout << "Move assigment for " << that.value_ << endl;

        key_ = exchange(that.key_, 0);
        value_ = move(that.value_);
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
    os << '[' << entry.key() << ", " << entry.value() << ']';
    return os;
}

class ExtendedEntry : public Entry {
public:
    ExtendedEntry(int key, const string& value) : Entry(key, value) {
        cout << "EE plain ctor for " << value << endl;
    }

    void sayHello() const override {
        cout << "EE hello " << value() << "!!!" << endl;
    }

    virtual ~ExtendedEntry() { cout << "EE dtor " << value() << endl; }
};

void aVector() {
    vector<int> data;
    cout << "Empty vector" << endl;
    cout << "Size is " << data.size() << endl;
    cout << "Capacity is " << data.capacity() << endl;

    data.push_back(2);
    data.push_back(12);
    data.push_back(42);
    cout << "Size is " << data.size() << endl;
    cout << "Capacity is " << data.capacity() << endl;
    cout << "First element is " << data.front() << endl;
    cout << "Last element is " << data.back() << endl;
}

void oVector() {
    cout << "Statically typed vector - no polymorphism!" << endl;
    vector<Entry> data{ {1, "Tom"}, {2, "Bob"} };
    for (const Entry& cur : data) {
        cout << cur << ' ';
    }
    cout << endl;

    data.push_back({ 3, "Kim" });

    ExtendedEntry wim{ 4, "Wim" };
    wim.sayHello();

    // BAD! Wim is sliced off !!!
    data.push_back(wim);
    for (const Entry& cur : data) {
        cur.sayHello();
    }
    cout << "Data out of scope" << endl;
}

void rpVector() {
    cout << "Raw Pointer Vector" << endl;
    vector<Entry*> data{ new Entry(1, "Tom"), new Entry(2, "Bob") };
    data.push_back(new Entry(3, "Kim"));

    data.push_back(new ExtendedEntry(4, "Wim"));
    for (const auto& cur : data) {
        cur->sayHello();
    }
    cout << "Access to an element in vector: ";
    data[0]->sayHello();

    cout << "Data out of scope, handmade cleanup!" << endl;
    for (auto& cur : data) {
        delete cur;
    }
    data.clear(); // paranoic
}

void spVector() {
    cout << "Shared Smart Pointer Vector" << endl;
    vector<shared_ptr<Entry>> data{ make_shared<Entry>(1, "Tom"), make_shared<Entry>(2, "Bob") };
    data.push_back(make_shared<Entry>(3, "Kim"));

    data.push_back(make_shared<ExtendedEntry>(4, "Wim"));
    for (const auto& cur : data) {
        cur->sayHello();
    }
    cout << "Access to an element in vector: ";
    data[0]->sayHello();
    cout << "Data out of scope" << endl;
}

void upVector() {
    cout << "Unique Smart Pointer Vector" << endl;
    vector<unique_ptr<Entry>> data;
    data.push_back(make_unique<Entry>(1, "Tom"));
    data.push_back(make_unique<Entry>(2, "Bob"));
    data.push_back(make_unique<Entry>(3, "Kim"));

    data.push_back(make_unique<ExtendedEntry>(4, "Wim"));
    for (const auto& cur : data) {
        cur->sayHello();
    }
    cout << "Access to an element in vector: ";
    data[0]->sayHello();
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
