// c++ -Wall b1_construct.cpp -lrt -pthread -o b1.exe
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <iostream>

namespace bi = boost::interprocess;

namespace {
    const char* SHMEM_NAME = "MySharedMemory";
    const char* COUNTER_NAME = "MyCounter";
    const char* AMOUNT_NAME = "MyAmount";
    const char* MESSAGE_NAME = "MyMessage";
}

// required to manage strings
typedef bi::allocator<char, bi::managed_shared_memory::segment_manager> CharAllocator;
typedef bi::basic_string<char, std::char_traits<char>, CharAllocator> MyString;

int main() {
    // ensure shared memory is not already set
    bi::shared_memory_object::remove(SHMEM_NAME);

    // instead of create_only the less restrictive open_or_create could be used
    bi::managed_shared_memory msm{ bi::create_only, SHMEM_NAME, 1024 };

    int* pCounter = msm.construct<int>(COUNTER_NAME)(42);
    std::cout << COUNTER_NAME << " placed in shared memory: " << *pCounter << '\n';

    double* pAmount = msm.construct<double>(AMOUNT_NAME)(42.24);
    std::cout << AMOUNT_NAME << " placed in shared memory: " << *pAmount << '\n';

    MyString* pMessage = msm.construct<MyString>(MESSAGE_NAME)("Hello!", msm.get_segment_manager());
    std::cout << MESSAGE_NAME << " placed in shared memory: " << *pMessage << '\n';
}
