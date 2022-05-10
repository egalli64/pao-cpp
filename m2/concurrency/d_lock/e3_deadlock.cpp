/*
 * g++ -pthread -o a.out e3_deadlock.cpp
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
    double v1 = 0;
    double v2 = 0;
    std::mutex mtx_1;
    std::mutex mtx_2;

    std::cout << "!!! This code could lead to a deadlock !!!\n";

    std::thread t1{ [&] {
        print("thread 1");

        std::lock_guard<std::mutex> lockA{ mtx_1 };
        print("lock 1");

        srand(time(nullptr));
        v1 = cbrt(log(rand() % 100 + 1));
        print("set v1", v1, v2);

        std::lock_guard<std::mutex> lockB{ mtx_1 };
        print("lock 2");

        std::swap(v1, v2);
        print("swap", v1, v2);
    } };

    std::thread t2{ [&] {
        print("thread 2");

        std::lock_guard<std::mutex> lockB{ mtx_2 };
        print("lock 2");

        v2 = cbrt(42);
        print("set v2", v1, v2);

        std::lock_guard<std::mutex> lockA{ mtx_1 };
        print("lock 1");

        std::swap(v1, v2);
        print("swap", v1, v2);
    } };

    t1.join();
    t2.join();
}
