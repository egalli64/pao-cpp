/*
 * g++ -pthread -o a.out e3_ref_f.cpp
 */
#include <functional>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

void adder_function(const std::vector<int>& values, int& result) {
    result = std::accumulate(values.begin(), values.end(), 0);
}

int main() {
    std::vector<int> values{ 1, 2, 3, 4, 5, 6 };
    int result;

    std::thread t{ adder_function, std::cref(values), std::ref(result) };
    t.join();

    std::cout << "Sum is " << result << '\n';
}
