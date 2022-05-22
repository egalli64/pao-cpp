#pragma once

#include <boost/interprocess/sync/interprocess_semaphore.hpp>

namespace bi = boost::interprocess;

struct MySharedData {
    MySharedData(int x);

    bi::interprocess_semaphore produce;
    bi::interprocess_semaphore consume;
    int stock;
};
