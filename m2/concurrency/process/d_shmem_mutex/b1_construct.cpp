// c++ -Wall b1_construct.cpp -lrt -pthread -o b1.exe
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

    try {
        bi::interprocess_mutex* pMtx = msm.construct<bi::interprocess_mutex>(MUTEX_NAME)();
        pMtx->lock();
        std::cout << COUNTER_NAME << ": " << counter << '\n';
        ++counter;
        std::cout << counter << '\n';
        pMtx->unlock();
    }
    catch (bi::interprocess_exception& ex) {
        std::cout << "Can't use mutex --> " << ex.what() << '\n';
    }
}
