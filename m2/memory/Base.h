#ifndef PAO_CPP_M2_MEMORY_BASE
#define PAO_CPP_M2_MEMORY_BASE
#include <iostream>
#include <utility>

class Base {
private:
    int x_;
public:
    Base(int x) : x_{ x } {
        std::cout << "Base ctor " << x_ << '\n';
    }

    Base(const Base& other) : x_{ other.x_ } {
        std::cout << "Base copy ctor " << x_ << '\n';
    }

    Base(Base&& other) noexcept {
        std::cout << "Base move ctor for " << other.x_ << '\n';

        x_ = std::exchange(other.x_, 0);
    }

    Base& operator=(const Base& other) {
        std::cout << "Base assigment for " << other.x_ << '\n';

        x_ = other.x_;
        return *this;
    }

    Base& operator=(Base&& other) {
        std::cout << "Base move assigment for " << other.x_ << '\n';

        x_ = std::exchange(other.x_, 0);
        return *this;
    }

    virtual void hello() const {
        std::cout << "Base hello " << x_ << '\n';
    }

    virtual ~Base() {
        std::cout << "Base dtor " << x_ << '\n';
    }

    friend std::ostream& operator<<(std::ostream& os, const Base& base) {
        return os << '{' << base.x_ << '}';
    }
};

#endif // PAO_CPP_M2_MEMORY_BASE
