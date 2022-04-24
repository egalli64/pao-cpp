#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> spEmpty;
    if (!spEmpty) {
        std::cout << "The current shared ptr is empty\n";
    }
    else {
        std::cout << "Unexpected!\n";
    }

    std::shared_ptr<int> sp{ new int{42} };
    if (sp) {
        std::cout << "The current shared ptr is _not_ empty\n";
    }
    else {
        std::cout << "Unexpected!\n";
    }
}
