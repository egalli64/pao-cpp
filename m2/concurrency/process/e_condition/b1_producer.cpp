// c++ -Wall b1_producer.cpp -lrt -pthread -o b1.exe
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/interprocess_condition.hpp> 
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include <boost/thread/thread_time.hpp>
#include <iostream>

namespace bi = boost::interprocess;
namespace bp = boost::posix_time;

namespace {
    const char* SHMEM_NAME = "MySharedMemory";
    const int SHMEM_SIZE = 1'024;
    const char* COUNTER_NAME = "MyCounter";
    const char* MUTEX_NAME = "MyMutex";
    const char* CONDITION_NAME = "MyCondition";
}

int main() {
    bi::managed_shared_memory msm{ bi::open_or_create, SHMEM_NAME, SHMEM_SIZE };
    bi::interprocess_mutex* pMtx = msm.find_or_construct<bi::interprocess_mutex>(MUTEX_NAME)();
    bi::interprocess_condition* pCnd = msm.find_or_construct<bi::interprocess_condition>(CONDITION_NAME)();
    bi::scoped_lock<bi::interprocess_mutex> lock{ *pMtx };

    int* pCounter = msm.find_or_construct<int>(COUNTER_NAME)(10);
    int& stock = *pCounter;

    std::cout << "Current stock: " << stock << std::flush;
    while (stock > 1) {
        pCnd->notify_all();
        if (pCnd->timed_wait(lock, boost::get_system_time() + bp::seconds(1))) {
            std::cout << ' ' << stock << std::flush;
            stock += 1;
        }
    }
    std::cout << " ... done!\n";

    // reset stock for next run
    stock = 10;

    pCnd->notify_all();
}
