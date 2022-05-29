/*
 * g++ -pthread -o a.out e2_guard.cpp
 */
#include <iostream>
#include <thread>
#include <mutex>

int main() {
    int result = 0;
    std::mutex mtx;

    std::thread t{ [&result, &mtx] {
        for (int i = 0; i < 50'000; ++i) {
            std::lock_guard<std::mutex> lock{ mtx };
            result++;
        }
    } };

    for (int i = 0; i < 50'000; ++i) {
        std::lock_guard<std::mutex> lock{ mtx };
        result++;
    }

    t.join();
    std::cout << "Guarded behavior: " << result << '\n';
}
