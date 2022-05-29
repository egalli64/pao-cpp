// g++ -pthread -o a.out e5_prod_cons.cpp
#include <iostream>
#include <mutex>
#include <thread>

namespace {
    std::mutex mtx;

    int stock = 10;

    void consumer() {
        while (stock > 0) {
            std::lock_guard<std::mutex> lock(mtx);
            stock -= 2;
            std::cout << "C:" << stock << ' ';
            // remember that yield is just a hint!
            std::this_thread::yield();
        }
    }
}

int main() {
    std::thread t{ consumer };

    while (stock > 0) {
        std::lock_guard<std::mutex> lock(mtx);

        std::cout << "P:" << ++stock << ' ';
        // remember that yield is just a hint!
        std::this_thread::yield();
    }

    t.join();
    std::cout << '\n';
}
