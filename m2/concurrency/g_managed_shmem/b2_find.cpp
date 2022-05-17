// c++ -Wall b2_find.cpp -lrt -pthread -o b2.exe
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <iostream>

namespace bi = boost::interprocess;

namespace {
    const char* SHMEM_NAME = "MySharedMemory";
    const char* COUNTER_NAME = "MyCounter";
    const char* C2_NAME = "AnotherCounter";
    const char* AMOUNT_NAME = "MyAmount";
    const char* VALUES_NAME = "MyValues";
    const char* MESSAGE_NAME = "MyMessage";
}

// required to manage strings
typedef bi::allocator<char, bi::managed_shared_memory::segment_manager> CharAllocator;
typedef bi::basic_string<char, std::char_traits<char>, CharAllocator> MyString;

int main() {
    bi::managed_shared_memory msm{ bi::open_only, SHMEM_NAME };

    std::pair<int*, std::size_t> pCounter = msm.find<int>(COUNTER_NAME);
    if (pCounter.first) {
        std::cout << COUNTER_NAME << ": " << *pCounter.first << '\n';
    }
    else {
        std::cout << COUNTER_NAME << " not found\n";
    }

    std::pair<int*, std::size_t> pC2 = msm.find<int>(C2_NAME);
    std::cout << C2_NAME;
    if (pC2.first) {
        std::cout << ": " << *pC2.first;
    }
    std::cout << ", size is " << pC2.second << '\n';

    std::pair<double*, std::size_t> pAmount = msm.find<double>(AMOUNT_NAME);
    if (pAmount.first) {
        std::cout << AMOUNT_NAME << ": " << *pAmount.first << '\n';
    }
    else {
        std::cout << AMOUNT_NAME << " not found\n";
    }

    std::pair<double*, std::size_t> pValues = msm.find<double>(VALUES_NAME);
    if (pValues.first) {
        std::cout << VALUES_NAME << ": ";
        for (size_t i = 0; i < pValues.second;++i) {
            std::cout << pValues.first[i] << ' ';
        }
        std::cout << '\n';
    }
    else {
        std::cout << VALUES_NAME << " not found\n";
    }

    std::pair<MyString*, std::size_t> pMessage = msm.find<MyString>(MESSAGE_NAME);
    if (pMessage.first) {
        std::cout << MESSAGE_NAME << ": " << *pMessage.first << '\n';
    }
    else {
        std::cout << MESSAGE_NAME << " not found\n";
    }
}
