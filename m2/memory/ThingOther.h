#ifndef PAO_CPP_M2_MEMORY_THING_OTHER
#define PAO_CPP_M2_MEMORY_THING_OTHER
#include "Thing.h"

class ThingOther : public Thing {
public:
    int z_;
    ThingOther(int x) : Thing(x), z_(x * 2) {
        std::cout << "ThingOther ctor\n";
    }

    void hello() const override {
        std::cout << "ThingOther ";
        Thing::hello();
    }

    void f() {
        std::cout << "f " << z_ << "\n";
    }

    ~ThingOther() {
        std::cout << "ThingOther dtor\n";
    }
};

#endif // PAO_CPP_M2_MEMORY_THING_OTHER
