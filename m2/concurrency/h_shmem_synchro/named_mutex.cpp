// c++ -Wall named_mutex.cpp -lrt -pthread -o nm.exe
#include <boost/interprocess/managed_shared_memory.hpp> 
#include <boost/interprocess/sync/named_mutex.hpp>
#include <iostream>  

namespace bi = boost::interprocess;

namespace {
    const char* SHMEM_NAME = "MySharedMemory";
    const char* COUNTER_NAME = "MyCounter";
}

int main() {
    bi::managed_shared_memory msm{ bi::open_only, SHMEM_NAME };

    std::pair<int*, std::size_t> pCounter = msm.find<int>(COUNTER_NAME);
    if (pCounter.first == nullptr) {
        std::cout << COUNTER_NAME << " not found\n";
        return 1;
    }

    bi::named_mutex mtx{ bi::open_or_create, "mtx" };

    int& counter = *pCounter.first;
    mtx.lock();
    std::cout << COUNTER_NAME << ": " << counter << '\n';
    ++counter;
    std::cout << counter << '\n';
    mtx.unlock();
}