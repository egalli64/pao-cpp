#ifndef PAO_CPP_M2_P1_D1_BASE
#define PAO_CPP_M2_P1_D1_BASE
#include <iostream>

class Base {
private:
    const int x_;
public:
    Base(int x) : x_{ x } {
        std::cout << "Base ctor " << x_ << std::endl;
    }

    virtual void hello() const {
        std::cout << "Base hello " << x_ << std::endl;
    }

    virtual ~Base() {
        std::cout << "Base dtor " << x_ << std::endl;
    }
};

#endif // PAO_CPP_M2_P1_D1_BASE
