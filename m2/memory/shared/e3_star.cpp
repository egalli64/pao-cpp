#include <iostream>
#include <memory>

int main() {
    std::cout << "Dereferencing a shared ptr\n";
    int* p = new int(42);
    std::shared_ptr<int> sp{ p };
    std::cout << "Raw ptr: " << p << ", value: " << *p << '\n';
    std::cout << "Smart ptr: " << sp << ", value:" << *sp << '\n';
}
