// c++ -Wall b2_consumer.cpp -lrt -pthread -o b2.exe
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/interprocess_semaphore.hpp>
#include <boost/date_time/posix_time/posix_time_duration.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <iostream>
#include "Cleaner.h"
#include "MySharedData.h"

namespace bi = boost::interprocess;

namespace {
    const char* SHMEM_NAME = "MySharedMemory";
    const char* DATA_NAME = "MySharedData";
}

int main() {
    bi::managed_shared_memory msm{ bi::open_only, SHMEM_NAME };

    std::pair<MySharedData*, std::size_t> pData = msm.find<MySharedData>(DATA_NAME);
    if (pData.first) {
        std::cout << DATA_NAME << " correctly accessed from shared memory\n";
    }
    else {
        std::cout << DATA_NAME << " not found\n";
        return EXIT_FAILURE;
    }
    MySharedData& data = *pData.first;

    while (data.stock > 0) {
        boost::posix_time::ptime waitTime(boost::posix_time::microsec_clock::universal_time());
        waitTime += boost::posix_time::seconds(3);
        if (!data.consume.timed_wait(waitTime)) {
            std::cout << "Timeout! ";
            break;
        }

        std::cout << data.stock << ' ' << std::flush;
        data.produce.post();
    }

    std::cout << "... consumer done\n";
}
