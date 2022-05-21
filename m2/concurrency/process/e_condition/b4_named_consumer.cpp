// c++ -Wall b4_named_consumer.cpp -lrt -pthread -o b4.exe
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/named_condition.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>
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
    bi::named_mutex mtx{ bi::open_only, MUTEX_NAME };
    bi::named_condition cnd{ bi::open_only, CONDITION_NAME };
    bi::scoped_lock<bi::named_mutex> lock{ mtx };

    std::pair<int*, std::size_t> pCounter = msm.find<int>(COUNTER_NAME);
    if (pCounter.first == nullptr) {
        std::cout << COUNTER_NAME << " not found\n";
        return EXIT_FAILURE;
    }

    int& stock = *pCounter.first;
    std::cout << "Consuming from stock: " << std::flush;
    while (stock > 0) {
        cnd.wait(lock);
        stock -= 2;
        std::cout << stock << ' ' << std::flush;
        cnd.notify_all();
    }
    std::cout << " done!\n";
}
