#ifndef PAO_CPP_M2_P1_D1_BASE
#define PAO_CPP_M2_P1_D1_BASE
#include <iostream>

class Base {
private:
    int x_;
public:
    Base(int x) : x_{ x } {
        std::cout << "Base ctor " << x_ << std::endl;
    }

    Base(const Base& other) : x_{ other.x_ } {
        std::cout << "Base copy ctor " << x_ << std::endl;
    }

    Base(Base&& other) noexcept {
        std::cout << "Base move ctor for " << other.x_ << std::endl;

        x_ = std::exchange(other.x_, 0);
    }

    Base& operator=(const Base& other) {
        std::cout << "Base assigment for " << other.x_ << std::endl;

        x_ = other.x_;
        return *this;
    }

    Base& operator=(Base&& other) {
        std::cout << "Base move assigment for " << other.x_ << std::endl;

        x_ = std::exchange(other.x_, 0);
        return *this;
    }

    virtual void hello() const {
        std::cout << "Base hello " << x_ << std::endl;
    }

    virtual ~Base() {
        std::cout << "Base dtor " << x_ << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Base& base) {
        return os << '{' << base.x_ << '}';
    }
};

#endif // PAO_CPP_M2_P1_D1_BASE
