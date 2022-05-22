// c++ -Wall b1_producer.cpp -lrt -pthread -o b1.exe
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/interprocess_semaphore.hpp>
#include <iostream>
#include "Cleaner.h"
#include "MySharedData.h"

namespace bi = boost::interprocess;

namespace {
    const char* SHMEM_NAME = "MySharedMemory";
    const int SHMEM_SIZE = 1'024;
    const char* DATA_NAME = "MySharedData";
}

// on startup produce is on and consume is off
inline MySharedData::MySharedData(int x) : produce(1), consume(0), stock(x) {}

int main() {
    Cleaner cleaner{ SHMEM_NAME };
    bi::managed_shared_memory msm{ bi::create_only, SHMEM_NAME, SHMEM_SIZE };

    MySharedData* pData = msm.construct<MySharedData>(DATA_NAME)(11);
    std::cout << DATA_NAME << " placed in shared memory\n";

    while (pData->stock > 0) {
        pData->produce.wait();

        // simulating a long job
        sleep(1);
        pData->stock -= 1;
        std::cout << pData->stock << ' ' << std::flush;

        pData->consume.post();
    }

    std::cout << "... producer done\n";
}
