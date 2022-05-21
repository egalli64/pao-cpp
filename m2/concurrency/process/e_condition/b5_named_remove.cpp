// c++ -Wall b5_named_remove.cpp -lrt -pthread -o b5.exe
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/named_condition.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>
#include <iostream>

namespace bi = boost::interprocess;

namespace {
    const char* SHMEM_NAME = "MySharedMemory";
    const char* MUTEX_NAME = "MyMutex";
    const char* CONDITION_NAME = "MyCondition";
}

int main() {
    bool result = bi::shared_memory_object::remove(SHMEM_NAME);
    std::cout << SHMEM_NAME << (result ? "" : " not") << " removed\n";

    result = bi::named_mutex::remove(MUTEX_NAME);
    std::cout << MUTEX_NAME << (result ? "" : " not") << " removed\n";

    result = bi::named_condition::remove(CONDITION_NAME);
    std::cout << CONDITION_NAME << (result ? "" : " not") << " removed\n";
}
