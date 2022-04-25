#include <iostream>
#include <memory>
#include "../Thing.h"

int main() {
    std::shared_ptr<Thing> sp = std::make_shared<Thing>(42);

    std::weak_ptr<Thing> wp{ sp };
    if (wp.expired()) {
        std::cout << "Unexpected!\n";
    }
    else {
        std::shared_ptr<Thing> spw = wp.lock();
        if (spw) {
            std::cout << "Shared ptr locked: ";
            spw->hello();
        }
        std::cout << "There are currently " << spw.use_count() << " resource owners\n";
    }

    std::cout << "Automatic unlock, " << sp.use_count() << " resource owner\n";

    sp.reset();
    std::cout << "After resetting the referred shared ptr, the weak ptr is expired!\n";

    if (!wp.expired()) {
        std::cout << "Unexpected!\n";
    }
    else {
        std::shared_ptr<Thing> spw = wp.lock();
        if (spw) {
            std::cout << "Unexpected!\n";
        }
        else {
            std::cout << "Expired weak ptr\n";
        }
    }
}
