#ifndef PAO_CPP_M2_MEMORY_THING_EXT
#define PAO_CPP_M2_MEMORY_THING_EXT
#include "Thing.h"

class ThingExt : public Thing {
public:
    ThingExt(int x) :Thing(x) {
        std::cout << "ThingExt ctor\n";
    }

    void hello() const override {
        std::cout << "ThingExt ";
        Thing::hello();
    }

    ~ThingExt() {
        std::cout << "ThingExt dtor\n";
    }
};

#endif // PAO_CPP_M2_MEMORY_THING_EXT
