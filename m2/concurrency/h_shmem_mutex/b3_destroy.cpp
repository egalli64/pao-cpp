// c++ -Wall b3_destroy.cpp -lrt -pthread -o b3.exe
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <iostream>

namespace bi = boost::interprocess;

namespace {
    const char* SHMEM_NAME = "MySharedMemory";
    const char* MUTEX_NAME = "MyMutex";
}

int main() {
    bi::managed_shared_memory msm{ bi::open_only, SHMEM_NAME };

    if (msm.destroy<bi::interprocess_mutex>(MUTEX_NAME)) {
        std::cout << MUTEX_NAME << " destroyed\n";
    }
    else {
        std::cout << MUTEX_NAME << " not destroyed\n";
    }
}
