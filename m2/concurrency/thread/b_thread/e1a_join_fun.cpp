/*
 * c++ -pthread -o a.out e1a_join_fun.cpp
 */
#include <iostream>
#include <thread>

namespace {
    void greeter(const std::string& greet) {
        for (int i = 0; i < 1'000; i++) {
            std::cout << greet[0];
        }

        std::cout << greet;
        std::cout << " from ";
        std::cout << std::this_thread::get_id();
        std::cout << '\n';
    }
}

int main() {
    std::cout << "Warning! This code is not thread safe!\n";

    std::thread t1{ greeter, "Hello" };
    std::thread t2{ greeter, "Goodbye" };

    std::cout << "Welcome to ";
    std::cout << "the main thread. ";
    std::cout << "Its id is ";
    std::cout << std::this_thread::get_id();
    std::cout << '\n';

    std::cout << "The access ";
    std::cout << "to the shared ";
    std::cout << "resource cout ";
    std::cout << "is not protected!";
    std::cout << '\n';

    t1.join();
    t2.join();
}
