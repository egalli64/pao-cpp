/*
 * g++ -pthread -o a.out e4_start.cpp
 */
#include <iostream>
#include <mutex>
#include <thread>

int main() {
    std::mutex mutex;

    mutex.lock();
    std::cout << "Main thread locks the mutex\n";

    std::thread t{ [&mutex] {
        mutex.lock();
        std::cout << "Child thread locks the mutex then unlocks it\n";
        mutex.unlock();
        std::cout << "Child thread does its job\n";
    } };

    std::cout << "When ready, the main thread unlocks the mutex\n";
    mutex.unlock();

    t.join();
    std::cout << "Main thread done\n";
}
