/*
 * g++ -pthread -o a.out e1_guard.cpp
 */
#include <algorithm>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

namespace {
    std::vector<int> data{};
    std::mutex mtx;

    void add(int value) {
        std::lock_guard<std::mutex> lock{ mtx };
        data.push_back(value);
    }

    bool contains(int value) {
        std::lock_guard<std::mutex> lock{ mtx };
        return std::find(data.begin(), data.end(), value) != data.end();
    }
}

int main() {
    if (contains(42)) {
        std::cout << "Unexpected\n";
    }

    std::thread t{ [] { add(42);} };

    if (contains(42)) {
        std::cout << "Could be, could be not\n";
    }

    t.join();
    if (!contains(42)) {
        std::cout << "Unexpected\n";
    }

    std::cout << "Done\n";
}
