#include <iostream>
#include <memory>

int main() {
    std::cout << "A plain shared ptr\n";
    std::shared_ptr<int> sp(new int(42));
    if (!sp) {
        std::cout << "Unexpected!\n";
    }
    std::cout << "Done\n";
}
