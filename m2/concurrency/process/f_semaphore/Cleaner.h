#pragma once

#include <boost/interprocess/managed_shared_memory.hpp>
#include <iostream>

namespace bi = boost::interprocess;

class Cleaner {
private:
    const char* smo_name_;
public:
    Cleaner(const char* smo_name) : smo_name_(smo_name) {
        std::cout << "Ensure " << smo_name_ << " is not already on\n";
        bi::shared_memory_object::remove(smo_name_);
    }
    ~Cleaner() {
        std::cout << "Drop " << smo_name_ << " on exit\n";
        bi::shared_memory_object::remove(smo_name_);
    }
};
