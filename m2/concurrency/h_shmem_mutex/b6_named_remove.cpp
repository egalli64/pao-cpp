// c++ -Wall b6_named_remove.cpp -lrt -pthread -o b6.exe
#include <boost/interprocess/sync/named_mutex.hpp>
#include <iostream>

namespace bi = boost::interprocess;

namespace {
    const char* MUTEX_NAME = "MyMutex";
}

int main() {
    if (bi::named_mutex::remove(MUTEX_NAME)) {
        std::cout << MUTEX_NAME << " destroyed\n";
    }
    else {
        std::cout << MUTEX_NAME << " not destroyed\n";
    }
}
