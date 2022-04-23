#include <iostream>
#include <memory>

int main() {
    std::cout << "A plain shared ptr by make_shared\n";
    std::shared_ptr<int> sp = std::make_shared<int>(42);
    if (sp.unique()) {
        std::cout << "There is only one owner\n";
        std::cout << "The use count is set to " << sp.use_count() << '\n';
    } else {
        std::cout << "Unexpected!\n";
    }
}
