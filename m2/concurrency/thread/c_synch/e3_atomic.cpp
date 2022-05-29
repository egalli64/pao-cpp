/*
 * c++ -pthread -o a.out e3_atomic.cpp
 */
#include <atomic>
#include <iostream>
#include <thread>

int main() {
    std::atomic<int> result{ 0 };

    std::thread t{ [&result] {
        for (int i = 0; i < 50'000; ++i) {
            result++;
        }
    } };

    for (int i = 0; i < 50'000; ++i) {
        result++;
    }

    t.join();
    std::cout << "No data race: " << result << '\n';
}
