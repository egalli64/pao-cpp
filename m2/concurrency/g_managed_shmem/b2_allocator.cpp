// c++ -Wall b2_allocator.cpp -lrt -pthread -o b2.exe
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <iostream>

namespace bi = boost::interprocess;

namespace {
    const char* SHMEM_NAME = "MySharedMemory";
    const char* MESSAGE_NAME = "MyMessage";
    const char* MESSAGE_VECTOR_NAME = "MyMessageVector";
}

typedef bi::allocator<char, bi::managed_shared_memory::segment_manager> CharAllocator;
typedef bi::basic_string<char, std::char_traits<char>, CharAllocator> MyString;

typedef bi::allocator<MyString, bi::managed_shared_memory::segment_manager> StringAllocator;
typedef bi::vector<MyString, StringAllocator> MyStringVector;

int main() {
    bi::managed_shared_memory msm{ bi::open_or_create, SHMEM_NAME, 1'024 };

    MyString* pMessage = msm.construct<MyString>(MESSAGE_NAME)("Hello!", msm.get_segment_manager());
    std::cout << MESSAGE_NAME << " in shared memory: " << *pMessage << '\n';

    MyString ms(msm.get_segment_manager());
    ms = "one";
    MyStringVector* pVector = msm.construct<MyStringVector>(MESSAGE_VECTOR_NAME)(msm.get_segment_manager());
    pVector->push_back(ms);
    ms = "two";
    pVector->push_back(ms);
    std::cout << MESSAGE_VECTOR_NAME << " in shared memory is sized " << pVector->size() << '\n';
}
