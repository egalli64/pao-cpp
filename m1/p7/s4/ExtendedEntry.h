#ifndef PAO_CPP_M1_P7_S4_EXTENDED_ENTRY_H
#define PAO_CPP_M1_P7_S4_EXTENDED_ENTRY_H

#include "Entry.h"

class ExtendedEntry : public Entry {
private:
    std::string tag_;
public:
    ExtendedEntry(int key, const std::string& value, const std::string& tag) : Entry(key, value), tag_(tag) {
        std::cout << "EE plain ctor for " << value << std::endl;
    }

    void sayHello() const override {
        std::cout << "EE hello " << value() << tag_ << std::endl;
    }

    virtual ~ExtendedEntry() {
        std::cout << "EE dtor " << value() << ", tag: " << tag_ << std::endl;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const ExtendedEntry& entry) {
        return os << '{' << entry.key() << ", " << entry.value() << ", " << entry.tag_ << '}';
    }
};

#endif // PAO_CPP_M1_P7_S4_EXTENDED_ENTRY_H
