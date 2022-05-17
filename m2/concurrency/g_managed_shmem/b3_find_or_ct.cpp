// c++ -Wall b3_find_or_ct.cpp -lrt -pthread -o b3.exe
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <iostream>

namespace bi = boost::interprocess;

namespace {
    const char* SHMEM_NAME = "MySharedMemory";
    const char* COUNTER_NAME = "MyCounter";
    const char* C2_NAME = "AnotherCounter";
}

// required to manage strings
typedef bi::allocator<char, bi::managed_shared_memory::segment_manager> CharAllocator;
typedef bi::basic_string<char, std::char_traits<char>, CharAllocator> MyString;

int main() {
    bi::managed_shared_memory msm{ bi::open_only, SHMEM_NAME };

    try {
        msm.construct<int>(COUNTER_NAME)(-1);
    }
    catch (bi::interprocess_exception& ex) {
        std::cout << COUNTER_NAME << " is already in shared memory -> " << ex.what() << '\n';
    }

    int* pCounter = msm.find_or_construct<int>(COUNTER_NAME)(21);
    std::cout << COUNTER_NAME << " is already in shared memory: " << *pCounter << '\n';
    *pCounter *= 2;
    std::cout << "Now " << COUNTER_NAME << " is " << *pCounter << '\n';

    int* pC2 = msm.find_or_construct<int>(C2_NAME)(99);
    std::cout << C2_NAME << " placed in shared memory: " << *pC2 << '\n';
}
