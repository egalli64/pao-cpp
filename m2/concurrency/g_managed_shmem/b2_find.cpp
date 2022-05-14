// c++ -Wall b2_find.cpp -lrt -pthread -o b2.exe
#include <boost/interprocess/managed_shared_memory.hpp>
#include <iostream>
#include <string>

namespace bi = boost::interprocess;

namespace {
    const char* SHMEM_NAME = "MySharedMemory";
    const char* COUNTER_NAME = "MyCounter";
    const char* AMOUNT_NAME = "MyAmount";
}

int main() {
    bi::managed_shared_memory msm{ bi::open_only, SHMEM_NAME };

    std::pair<int*, std::size_t> pCounter = msm.find<int>(COUNTER_NAME);
    if (pCounter.second != 1) {
        std::cout << "A single counter was expected!\n";
    }
    else if (pCounter.first) {
        std::cout << COUNTER_NAME << ": " << *pCounter.first << '\n';
    }

    std::pair<double*, std::size_t> pAmount = msm.find<double>(AMOUNT_NAME);
    if (pAmount.first) {
        std::cout << AMOUNT_NAME << ": " << *pAmount.first << '\n';
    }
}
