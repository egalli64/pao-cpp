#ifndef PAO_CPP_M1_P7_S4_ENTRY_H
#define PAO_CPP_M1_P7_S4_ENTRY_H

#include <iostream>
#include <string>
#include <utility>

class Entry {
private:
    int key_;
    std::string value_;
public:
    Entry(int key, const std::string& value) : key_(key), value_(value) {
        std::cout << "Plain ctor for " << value_ << std::endl;
    }

    Entry(const Entry& other) : key_(other.key_), value_(other.value_) {
        std::cout << "Copy ctor for " << value_ << std::endl;
    }

    Entry(Entry&& other) noexcept {
        std::cout << "Move ctor for " << other.value_ << std::endl;

        key_ = std::exchange(other.key_, 0);
        value_ = std::move(other.value_);
    }

    Entry& operator=(Entry&& other) {
        std::cout << "Move assigment for " << other.value_ << std::endl;

        key_ = std::exchange(other.key_, 0);
        value_ = std::move(other.value_);
        return *this;
    }

    int key() const { return key_; }
    const std::string& value() const { return value_; }

    void setKey(int key) { key_ = key; };
    void setValue(const std::string& value) { value_ = value; }

    virtual void sayHello() const {
        std::cout << "Hello " << value() << std::endl;
    }

    virtual ~Entry() {
        std::cout << "dtor " << key_ << ' ' << value_ << std::endl;
    }
};

inline std::ostream& operator<<(std::ostream& os, const Entry& entry) {
    return os << '{' << entry.key() << ", " << entry.value() << '}';
}

#endif // PAO_CPP_M1_P7_S4_ENTRY_H
