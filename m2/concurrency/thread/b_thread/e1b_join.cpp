/*
 * g++ -pthread -o a.out e1b_join.cpp -lboost_system -lboost_thread
 */
#include <iostream>
#include <boost/thread.hpp>

void greeter() {
    std::cout << "Hello from thread " << boost::this_thread::get_id() << '\n';
}

class Greeter {
public:
    void operator()() const {
        std::cout << "Cheers from thread " << boost::this_thread::get_id() << '\n';
    }
};

int main() {
    std::cout << "Warning! This code is not thread safe!\n";

    boost::thread t1{ greeter };
    boost::thread t2{ Greeter() };
    boost::thread t3{ [] { std::cout << "Goodbye from thread " << boost::this_thread::get_id() << '\n'; } };

    std::cout << "The main thread is ";
    std::cout << boost::this_thread::get_id();
    std::cout << '\n';

    std::cout << "The access to the resource cout is shared but not protected!\n";

    t1.join();
    t2.join();
    t3.join();
}
