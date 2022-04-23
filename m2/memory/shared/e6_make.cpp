#include <iostream>
#include <memory>

int main() {
    std::cout << "A plain shared ptr by make_shared\n";
    std::shared_ptr<int> sp = std::make_shared<int>(42);
    if (!sp) {
        std::cout << "Unexpected!\n";
    }
    std::cout << "Value is " << *sp << '\n';
}
