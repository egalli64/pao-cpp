/*
 * g++ -pthread -o a.out e3_ref_fob.cpp
 */
#include <functional>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

class Adder {
private:
    const std::vector<int>& values_;
    int& result_;
public:
    Adder(const std::vector<int>& values, int& result) : values_(values), result_(result) {}
    void operator()() const {
        result_ = std::accumulate(values_.begin(), values_.end(), 0);
    }
};

int main() {
    std::vector<int> values{ 1, 2, 3, 4, 5, 6 };
    int result;

    std::thread t{ Adder(values, result) };
    t.join();

    std::cout << "Sum is " << result << '\n';
}
