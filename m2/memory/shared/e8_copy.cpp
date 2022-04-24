#include <iostream>
#include <memory>
#include "../Base.h"

int main() {
    std::cout << "Shared ptr copy ctor behavior\n\n";
    std::shared_ptr<Base> sp = std::make_shared<Base>(42);

    if (sp.unique()) {
        std::shared_ptr<Base> sp2{ sp };
        std::cout << "A new shared ptr created by copy just increase the count\n";
        if (!sp.unique()) {
            std::cout << "There are more owners\n";
            std::cout << "The use count is set to " << sp.use_count() << '\n';
        }
    }
    else {
        std::cout << "Unexpected!\n";
    }

    if (sp.unique()) {
        std::cout << "The shared ptr dtor decrease the use count\n";
    }

    std::cout << "The last shared ptr exiting of scope causes the resource destruction\n";
}
