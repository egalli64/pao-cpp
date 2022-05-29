/*
 * c++ -pthread -o a.out e2_on_int.cpp
 */
#include <iostream>
#include <mutex>
#include <thread>

int main() {
    std::mutex mtx;
    int result = 0;

    std::thread t{ [&] {
        for (int i = 0; i < 50'000; ++i) {
            mtx.lock();
            result++;
            mtx.unlock();
        }
    } };

    for (int i = 0; i < 50'000; ++i) {
        mtx.lock();
        result++;
        mtx.unlock();
    }

    t.join();
    std::cout << "No data race: " << result << '\n';
}
