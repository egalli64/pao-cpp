// c++ -Wall b2_allocator.cpp -lrt -pthread -o b2.exe
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <iostream>

namespace bi = boost::interprocess;

namespace {
    const char* SHMEM_NAME = "MySharedMemory";
    const char* MESSAGE_NAME = "MyMessage";
}

typedef bi::allocator<char, bi::managed_shared_memory::segment_manager> CharAllocator;
typedef bi::basic_string<char, std::char_traits<char>, CharAllocator> MyString;

int main() {
    bi::managed_shared_memory msm{ bi::open_or_create, SHMEM_NAME, 1'024 };

    MyString* pMessage = msm.construct<MyString>(MESSAGE_NAME)("Hello!", msm.get_segment_manager());
    std::cout << MESSAGE_NAME << " placed in shared memory: " << *pMessage << '\n';
}
