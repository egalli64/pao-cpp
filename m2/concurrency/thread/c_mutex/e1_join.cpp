/*
 * c++ -pthread -o a.out e1_join.cpp
 */
#include <iostream>
#include <thread>

int main() {
    int result = 0;
    std::cout << "Result is " << result << '\n';

    std::thread t{ [&result] {result = 42;} };
    t.join();

    std::cout << "Result now is " << result << '\n';
}
