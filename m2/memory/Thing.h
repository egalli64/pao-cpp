#ifndef PAO_CPP_M2_MEMORY_THING
#define PAO_CPP_M2_MEMORY_THING
#include <iostream>
#include <utility>

class Thing {
private:
    int x_;
public:
    Thing(int x) : x_{ x } {
        std::cout << "Thing ctor " << x_ << '\n';
    }

    Thing(const Thing& other) : x_{ other.x_ } {
        std::cout << "Thing copy ctor " << x_ << '\n';
    }

    Thing(Thing&& other) noexcept {
        std::cout << "Thing move ctor for " << other.x_ << '\n';

        x_ = std::exchange(other.x_, 0);
    }

    Thing& operator=(const Thing& other) {
        std::cout << "Thing assigment for " << other.x_ << '\n';

        x_ = other.x_;
        return *this;
    }

    Thing& operator=(Thing&& other) {
        std::cout << "Thing move assigment for " << other.x_ << '\n';

        x_ = std::exchange(other.x_, 0);
        return *this;
    }

    virtual void hello() const {
        std::cout << "Thing hello " << x_ << '\n';
    }

    virtual ~Thing() {
        std::cout << "Thing dtor " << x_ << '\n';
    }

    friend std::ostream& operator<<(std::ostream& os, const Thing& thing) {
        return os << '{' << thing.x_ << '}';
    }
};

#endif // PAO_CPP_M2_MEMORY_THING
