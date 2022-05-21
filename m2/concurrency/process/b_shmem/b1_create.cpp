// c++ -Wall b1_create.cpp -lrt -o b1.exe
#include <boost/interprocess/shared_memory_object.hpp>
#include <iostream>

namespace bi = boost::interprocess;

namespace {
    const char* SHMEM_NAME = "MySharedMemory";
}

int main() {
    try {
        // instead of create_only the more permissive open_or_create could be passed
        bi::shared_memory_object smo{ bi::create_only, SHMEM_NAME, bi::read_write };

        smo.truncate(1024);

        std::cout << smo.get_name() << " created";
        bi::offset_t size;
        if (smo.get_size(size)) {
            std::cout << " with size " << size;
        }
        std::cout << '\n';
    } catch(bi::interprocess_exception& ex) {
        std::cout << "Can't create shared memory: " << ex.what() << '\n';
    }
}
