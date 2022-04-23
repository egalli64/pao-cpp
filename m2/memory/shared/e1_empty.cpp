#include <iostream>
#include <memory>

int main() {
    std::cout << "An empty shared ptr\n";
    std::shared_ptr<int> sp;
    if (sp) {
        std::cout << "Unexpected!\n";
    }
    std::cout << "Done\n";
}
