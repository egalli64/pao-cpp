#ifndef PAO_CPP_M2_P1_D1_DERIVED
#define PAO_CPP_M2_P1_D1_DERIVED
#include "Base.h"

class Derived : public Base {
public:
    Derived(int x) : Base(x) {}

    void hello() const override {
        std::cout << "Derived ";
        Base::hello();
    }

    ~Derived() {
        std::cout << "Derived dtor" << std::endl;
    }
};

#endif // PAO_CPP_M2_P1_D1_DERIVED
