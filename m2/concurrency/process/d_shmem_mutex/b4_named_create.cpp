// c++ -Wall b4_named_create.cpp -lrt -pthread -o b4.exe
#include <boost/interprocess/managed_shared_memory.hpp> 
#include <boost/interprocess/sync/named_mutex.hpp>
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
        return 1;
    }

    int& counter = *pCounter.first;

    try {
        bi::named_mutex mtx{ bi::create_only, MUTEX_NAME };
        mtx.lock();
        std::cout << COUNTER_NAME << ": " << counter << '\n';
        ++counter;
        std::cout << counter << '\n';
        mtx.unlock();
    }
    catch (bi::interprocess_exception& ex) {
        std::cout << "Can't use mutex --> " << ex.what() << '\n';
    }
}