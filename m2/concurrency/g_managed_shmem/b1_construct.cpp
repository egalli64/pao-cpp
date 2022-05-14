// c++ -Wall b1_construct.cpp -lrt -pthread -o b1.exe
#include <boost/interprocess/managed_shared_memory.hpp>
#include <iostream>

namespace bi = boost::interprocess;

namespace {
    const char* SHMEM_NAME = "MySharedMemory";
    const char* COUNTER_NAME = "MyCounter";
    const char* AMOUNT_NAME = "MyAmount";
}

int main() {
    // ensure shared memory is not already set
    bi::shared_memory_object::remove(SHMEM_NAME);

    // instead of create_only the less restrictive open_or_create could be used
    bi::managed_shared_memory msm{ bi::create_only, SHMEM_NAME, 1024 };

    int* pCounter = msm.construct<int>(COUNTER_NAME)(42);
    std::cout << COUNTER_NAME << " placed in shared memory: " << *pCounter << '\n';

    double* pAmount = msm.construct<double>(AMOUNT_NAME)(42.24);
    std::cout << AMOUNT_NAME << " placed in shared memory: " << *pAmount << '\n';
}
