/*
 * g++ -pthread -o a.out e1_join_f.cpp
 */
#include <iostream>
#include <thread>

void hello() {
    std::cout << "Hello from thread ";
    std::cout << std::this_thread::get_id();
    std::cout << '\n';
}

void goodbye() {
    std::cout << "Hello from thread ";
    std::cout << std::this_thread::get_id();
    std::cout << '\n';
}

int main() {
    std::cout << "Warning! This code is not thread safe!\n";

    std::thread t1{ hello };

    std::cout << "The main thread is ";
    std::cout << std::this_thread::get_id();
    std::cout << '\n';

    std::thread t2{ goodbye };

    std::cout << "The access to the resource cout is shared but not protected!\n";

    t1.join();
    t2.join();
}
