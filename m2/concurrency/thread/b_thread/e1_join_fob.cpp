/*
 * g++ -pthread -o a.out e1_join_fob.cpp
 */
#include <iostream>
#include <string>
#include <thread>

class Greeter {
private:
    std::string greet_;
public:
    Greeter(const std::string& greet) : greet_(greet) {}
    void operator()() const {
        std::cout << greet_;
        std::cout << " from thread ";
        std::cout << std::this_thread::get_id();
        std::cout << '\n';
    }
};

int main() {
    std::cout << "Warning! This code is not thread safe!\n";

    std::thread t1{ Greeter("Hello") };

    std::cout << "The main thread is ";
    std::cout << std::this_thread::get_id();
    std::cout << '\n';

    std::thread t2{ Greeter("Goodbye") };

    std::cout << "The access to the resource cout is shared but not protected!\n";

    t1.join();
    t2.join();
}
