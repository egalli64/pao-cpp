/*
 * g++ -pthread -o a.out e1.cpp
 */
#include <iostream>
#include <thread>

void a_function() {
    std::cout << "Run a function in another thread\n";
}

class AFunctor {
public:
    void operator()() const {
        std::cout << "Run a functor in another thread\n";
    }
};

int main() {
    std::cout << "Warning! This code is not thread safe!\n";

    std::thread t1{ a_function };
    std::thread t2{ AFunctor() };
    std::thread t3{ [] { std::cout << "Run a lambda in another thread\n"; } };

    std::cout << "Warning! This code is not thread safe!\n";

    t1.join();
    t2.join();
    t3.join();
}
