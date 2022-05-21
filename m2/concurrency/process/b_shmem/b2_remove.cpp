// c++ -Wall b2_remove.cpp -lrt -o b2.exe
#include <boost/interprocess/shared_memory_object.hpp>
#include <iostream>

namespace bi = boost::interprocess;

namespace {
    const char* SHMEM_NAME = "MySharedMemory";
}

int main() {
    try {
        bi::shared_memory_object smo{ bi::open_only, SHMEM_NAME, bi::read_only };
        bi::shared_memory_object::remove(SHMEM_NAME);
    } catch(bi::interprocess_exception& ex) {
        std::cout << "Can't open/remove shared memory: " << ex.what() << '\n';
    }
}
