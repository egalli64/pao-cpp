// c++ -Wall b5_destroy.cpp -lrt -pthread -o b5.exe
#include <boost/interprocess/managed_shared_memory.hpp>
#include <iostream>

namespace bi = boost::interprocess;

namespace {
    const char* SHMEM_NAME = "MySharedMemory";
    const char* C2_NAME = "AnotherCounter";
    const char* VALUES_NAME = "MyValues";
}

int main() {
    bi::managed_shared_memory msm{ bi::open_only, SHMEM_NAME };

    if (msm.destroy<int>(C2_NAME)) {
        std::cout << C2_NAME << " destroyed\n";
    }
    else {
        std::cout << C2_NAME << " not destroyed\n";
    }

    std::pair<double*, std::size_t> pValues = msm.find<double>(VALUES_NAME);
    if (pValues.first) {
        std::cout << VALUES_NAME << " found, is going to be destroyed by ptr\n";
        msm.destroy_ptr<double>(pValues.first);
    }
    else {
        std::cout << VALUES_NAME << " not found\n";
    }
}
