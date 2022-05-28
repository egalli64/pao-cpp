/*
 * c++ -pthread -o a.out e1c_join_lambda.cpp
 */
#include <iostream>
#include <string>
#include <thread>

int main() {
    std::cout << "Warning! This code is not thread safe!\n";

    auto greeter = [] (const std::string& s) {
        for (int i = 0; i < 1'000; i++) {
            std::cout << s[0];
        }

        std::cout << s;
        std::cout << " from ";
        std::cout << std::this_thread::get_id();
        std::cout << '\n';
    };

    std::thread t1{ greeter, "Hello" };
    std::thread t2{ greeter, "Goodbye" };

    std::cout << "The main thread is ";
    std::cout << std::this_thread::get_id();
    std::cout << '\n';

    std::cout << "The access to the resource cout is shared but not protected!\n";

    t1.join();
    t2.join();
}
