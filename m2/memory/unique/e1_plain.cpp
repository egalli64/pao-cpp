#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> upEmpty;
    if (!upEmpty) {
        std::cout << "The current unique ptr is empty\n";
    }
    else {
        std::cout << "Unexpected!\n";
    }

    std::unique_ptr<int> up{ new int{42} };
    if (up) {
        std::cout << "The current unique ptr is _not_ empty\n";
    }
    else {
        std::cout << "Unexpected!\n";
    }
}
