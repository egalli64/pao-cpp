/*
 * g++ -pthread -o a.out e2_detach.cpp
 */
#include <iostream>
#include <thread>

void a_function() {
    std::cout << "Enter task\n";
    std::this_thread::sleep_for(std::chrono::milliseconds{ 100 });
    std::cout << "Task done!\n";
}

int main() {
    std::thread t1{ a_function };
    std::cout << "Do not wait for task\n";
    t1.detach();

    std::cout << "Main done!\n";
    pthread_exit(nullptr);
}
