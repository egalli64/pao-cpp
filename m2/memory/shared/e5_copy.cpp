#include <iostream>
#include <memory>
#include "../Thing.h"

int main() {
    std::shared_ptr<Thing> sp = std::make_shared<Thing>(42);

    if (sp.unique()) {
        std::shared_ptr<Thing> sp2{ sp };
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
