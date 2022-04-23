#include <iostream>
#include <memory>

int main() {
    std::cout << "Dereferencing a shared ptr\n";
    std::shared_ptr<int> sp(new int(42));
    std::cout << "The value is " << *sp << '\n';
}
