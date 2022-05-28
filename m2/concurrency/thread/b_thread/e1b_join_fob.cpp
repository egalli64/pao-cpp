/*
 * c++ -pthread -o a.out e1b_join_fob.cpp
 */
#include <iostream>
#include <string>
#include <thread>

namespace {
    class Greeter {
    private:
        std::string greet_;
    public:
        Greeter(const std::string& greet) : greet_(greet) {}
        void operator()() const {
            for (int i = 0; i < 1'000; i++) {
                std::cout << greet_[0];
            }

            std::cout << greet_;
            std::cout << " from ";
            std::cout << std::this_thread::get_id();
            std::cout << '\n';
        }
    };
}

int main() {
    std::cout << "Warning! This code is not thread safe!\n";

    std::thread t1{ Greeter("Hello") };

    std::cout << "The main thread is ";
    std::cout << std::this_thread::get_id();
    std::cout << '\n';

    std::thread t2{ Greeter("Goodbye") };

    std::cout << "The access ";
    std::cout << "to the shared ";
    std::cout << "resource cout ";
    std::cout << "is not protected!";
    std::cout << '\n';

    t1.join();
    t2.join();
}
