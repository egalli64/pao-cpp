// c++ -Wall b2_remove.cpp -lrt -o b2.exe
#include <boost/interprocess/shared_memory_object.hpp>
#include <iostream>

namespace bi = boost::interprocess;

namespace {
    const char* SHMEM_NAME = "MySharedMemory";
}

int main() {
    std::cout << SHMEM_NAME;
    if (!bi::shared_memory_object::remove(SHMEM_NAME)) {
        std::cout << " not";
    }
    std::cout << " removed\n";
}
