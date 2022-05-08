/*
 * g++ -pthread -o a.out e3_ref_lambda.cpp
 */
#include <functional>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

int main() {
    std::vector<int> values{ 1, 2, 3, 4, 5, 6 };
    int result;

    std::thread t{ [&values, &result] { result = std::accumulate(values.begin(), values.end(), 0); } };
    t.join();

    std::cout << "Sum is " << result << '\n';
}
