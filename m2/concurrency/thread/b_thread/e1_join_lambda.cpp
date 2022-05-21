/*
 * g++ -pthread -o a.out e1_join_lambda.cpp
 */
#include <iostream>
#include <string>
#include <thread>

int main() {
    std::cout << "Warning! This code is not thread safe!\n";

    std::thread t{ [] {std::cout << "Hello from thread " << std::this_thread::get_id() << '\n';} };

    std::cout << "The main thread is ";
    std::cout << std::this_thread::get_id();
    std::cout << '\n';

    std::cout << "The access to the resource cout is shared but not protected!\n";

    t.join();
}
