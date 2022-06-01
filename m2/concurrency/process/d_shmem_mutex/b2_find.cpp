// c++ -Wall b2_find.cpp -lrt -pthread -o b2.exe
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <iostream>

namespace bi = boost::interprocess;

namespace {
    const char* SHMEM_NAME = "MySharedMemory";
    const char* COUNTER_NAME = "MyCounter";
    const char* MUTEX_NAME = "MyMutex";
}

int main() {
    bi::managed_shared_memory msm{ bi::open_only, SHMEM_NAME };

    std::pair<int*, std::size_t> pCounter = msm.find<int>(COUNTER_NAME);
    if (pCounter.first == nullptr) {
        std::cout << COUNTER_NAME << " not found\n";
        return EXIT_FAILURE;
    }

    int& counter = *pCounter.first;

    std::pair<bi::interprocess_mutex*, std::size_t> pMtx = msm.find<bi::interprocess_mutex>(MUTEX_NAME);
    if (pMtx.first == nullptr) {
        std::cout << MUTEX_NAME << " not found\n";
        return EXIT_FAILURE;
    }

    bi::interprocess_mutex& mtx = *pMtx.first;

    mtx.lock();
    std::cout << COUNTER_NAME << ": " << counter << '\n';
    ++counter;
    std::cout << counter << '\n';
    mtx.unlock();
}
