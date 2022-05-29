/*
 * c++ -pthread -o a.out e2_race.cpp
 */
#include <iostream>
#include <thread>

int main() {
    int result = 0;

    std::thread t{ [&result] {
        for (int i = 0; i < 50'000; ++i) {
            result++;
        }
    } };

    for (int i = 0; i < 50'000; ++i) {
        result++;
    }

    t.join();
    std::cout << "Problematic data race: " << result << "!\n";
}
