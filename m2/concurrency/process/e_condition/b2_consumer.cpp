// c++ -Wall b2_consumer.cpp -lrt -pthread -o b2.exe
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/interprocess_condition.hpp> 
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include <iostream>

namespace bi = boost::interprocess;

namespace {
    const char* SHMEM_NAME = "MySharedMemory";
    const char* COUNTER_NAME = "MyCounter";
    const char* MUTEX_NAME = "MyMutex";
    const char* CONDITION_NAME = "MyCondition";
}

int main() {
    bi::managed_shared_memory msm{ bi::open_only, SHMEM_NAME };

    std::pair<bi::interprocess_mutex*, std::size_t> pMtx = msm.find<bi::interprocess_mutex>(MUTEX_NAME);
    if (pMtx.first == nullptr) {
        std::cout << MUTEX_NAME << " not found\n";
        return 1;
    }
    bi::interprocess_mutex& mtx = *pMtx.first;

    std::pair<bi::interprocess_condition*, std::size_t> pCnd = msm.find<bi::interprocess_condition>(CONDITION_NAME);
    if (pCnd.first == nullptr) {
        std::cout << CONDITION_NAME << " not found\n";
        return 1;
    }
    bi::interprocess_condition& cnd = *pCnd.first;

    bi::scoped_lock<bi::interprocess_mutex> lock{ mtx };

    std::pair<int*, std::size_t> pCounter = msm.find<int>(COUNTER_NAME);
    if (pCounter.first == nullptr) {
        std::cout << COUNTER_NAME << " not found\n";
        return 1;
    }

    int& stock = *pCounter.first;
    std::cout << "Consuming from stock: " << std::flush;
    while (stock > 0) {
        cnd.wait(lock);
        stock -= 2;
        std::cout << stock << ' ' << std::flush;
        cnd.notify_all();
    }
    std::cout << "done!\n";
}
