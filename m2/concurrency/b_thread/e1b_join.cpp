/*
 * g++ -pthread -o a.out e1b_join.cpp -lboost_system -lboost_thread
 */
#include <iostream>
#include <boost/thread.hpp>

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

    boost::thread t1{ a_function };
    boost::thread t2{ AFunctor() };
    boost::thread t3{ [] { std::cout << "Run a lambda in another thread\n"; } };

    std::cout << "The access to the resource cout is shared but not protected!\n";

    t1.join();
    t2.join();
    t3.join();
}
