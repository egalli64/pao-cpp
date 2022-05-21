/*
 * g++ -pthread -o a.out e2b_detach.cpp -lboost_system -lboost_thread  -lboost_chrono
 */
#include <iostream>
#include <boost/chrono.hpp>
#include <boost/thread.hpp>

void a_function() {
    std::cout << "Enter task\n";
    boost::this_thread::sleep_for(boost::chrono::milliseconds{ 100 });
    std::cout << "Task done!\n";
}

int main() {
    boost::thread t1{ a_function };
    std::cout << "Do not wait for task\n";
    t1.detach();

    std::cout << "Main done!\n";
    pthread_exit(nullptr);
}
