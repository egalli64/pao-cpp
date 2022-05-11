/*
 * g++ -pthread -o a.out e4_lock.cpp
 */
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>
#include <mutex>
#include <utility>

namespace {
    std::mutex mtx;

    void print(const char* message) {
        std::lock_guard<std::mutex> lock{ mtx };
        std::cout << std::this_thread::get_id() << ' ' << message << '\n';
    }

    void print(const char* message, double a, double b) {
        std::lock_guard<std::mutex> lock{ mtx };
        std::cout << std::this_thread::get_id() << ' ' << message << ' ' << a << ", " << b << '\n';
    }
}

int main() {
    double v1 = 12.23;
    double v2 = 32.21;
    std::mutex mtx_1;
    std::mutex mtx_2;

    std::thread t1{ [&] {
        print("thread 1");

        srand(time(nullptr));
        v1 = cbrt(log(rand() % 100 + 1));
        print("set v1", v1, v2);

        std::lock(mtx_1, mtx_2);
        std::lock_guard<std::mutex> lock1{ mtx_1, std::adopt_lock };
        std::lock_guard<std::mutex> lock2{ mtx_2, std::adopt_lock };
        print("thread 1 locked");

        std::swap(v1, v2);
        print("swap 1 ->", v1, v2);
    } };

    std::thread t2{ [&] {
        print("thread 2");

        v2 = cbrt(42);
        print("set v2", v1, v2);

        std::lock(mtx_1, mtx_2);
        std::lock_guard<std::mutex> lock2{ mtx_2, std::adopt_lock };
        std::lock_guard<std::mutex> lock1{ mtx_1, std::adopt_lock };
        print("thread 2 locked");

        std::swap(v1, v2);
        print("swap 2 ->", v1, v2);
    } };

    t1.join();
    t2.join();
}
