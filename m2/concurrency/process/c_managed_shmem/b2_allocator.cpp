// c++ -Wall b2_allocator.cpp -lrt -pthread -o b2.exe
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <iostream>

namespace bi = boost::interprocess;

namespace {
    const char* SHMEM_NAME = "MySharedMemory";
    const int SHMEM_SIZE = 1'024;

    const char* MESSAGE_NAME = "MyMessage";
    const char* MESSAGE_VECTOR_NAME = "MyMessageVector";
}

typedef bi::allocator<char, bi::managed_shared_memory::segment_manager> CharAllocator;
typedef bi::basic_string<char, std::char_traits<char>, CharAllocator> MyString;

typedef bi::allocator<MyString, bi::managed_shared_memory::segment_manager> StringAllocator;
typedef bi::vector<MyString, StringAllocator> MyStringVector;

int main() {
    bi::managed_shared_memory msm{ bi::open_or_create, SHMEM_NAME, SHMEM_SIZE };

    MyString* pMessage = msm.construct<MyString>(MESSAGE_NAME)("Hello!", msm.get_segment_manager());
    std::cout << MESSAGE_NAME << " in shared memory: " << *pMessage << '\n';

    MyStringVector* pVector = msm.construct<MyStringVector>(MESSAGE_VECTOR_NAME)(msm.get_segment_manager());

    MyString ms(msm.get_segment_manager());
    ms = "one";
    pVector->push_back(ms);
    ms = "two";
    pVector->push_back(ms);

    std::cout << MESSAGE_VECTOR_NAME << " in shared memory is sized " << pVector->size() << '\n';
}
