/*
 * c++ -pthread -o a.out e1_on_cout.cpp
 */
#include <iostream>
#include <string>
#include <mutex>
#include <thread>

int main() {
    std::cout << "Cout access protected by mutex\n";
    std::mutex mtx;

    auto greeter = [&mtx] (const std::string& s) {
        mtx.lock();
        for (int i = 0; i < 1'000; i++) {
            std::cout << s[0];
        }

        std::cout << s;
        std::cout << " from ";
        std::cout << std::this_thread::get_id();
        std::cout << '\n';
        mtx.unlock();
    };

    std::thread t1{ greeter, "Hello" };
    std::thread t2{ greeter, "Goodbye" };

    mtx.lock();
    std::cout << "The main thread is ";
    std::cout << std::this_thread::get_id();
    std::cout << '\n';
    mtx.unlock();

    t1.join();
    t2.join();
}
