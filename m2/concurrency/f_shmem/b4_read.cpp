// c++ -Wall b4_read.cpp -lrt -o b4.exe
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <cstring>
#include <iostream>

namespace bi = boost::interprocess;

namespace {
    const char* SHMEM_NAME = "MySharedMemory";
}

int main() {
    try {
        bi::shared_memory_object smo{ bi::open_only, SHMEM_NAME, bi::read_write };
        bi::mapped_region region{ smo, bi::read_only };

        const char* data = static_cast<const char*>(region.get_address());
        std::cout << data << '\n';
    }
    catch (bi::interprocess_exception& ex) {
        std::cout << "Can't open shared memory: " << ex.what() << '\n';
    }
}
