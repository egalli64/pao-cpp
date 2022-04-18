/*
 * g++ -pthread -o a.out e2b.cpp -lboost_system -lboost_thread
 */
#include <functional>
#include <iostream>
#include <numeric>
#include <boost/thread.hpp>
#include <vector>

void adder_function(const std::vector<int>& values, int& result) {
    result = std::accumulate(values.begin(), values.end(), 0);
}

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
    int r_1;
    int r_2;
    int r_3;

    boost::thread t1{ adder_function, std::cref(values), std::ref(r_1) };
    boost::thread t2{ Adder(values, r_2) };
    boost::thread t3{ [&] { r_3 = std::accumulate(values.begin(), values.end(), 0); } };

    t1.join();
    t2.join();
    t3.join();

    std::cout << r_1 << ", " << r_2 << ", " << r_3 << '\n';
}
