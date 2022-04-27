#ifndef PAO_CPP_M2_MEMORY_WEAK_PROJECT
#define PAO_CPP_M2_MEMORY_WEAK_PROJECT
#include <iostream>
#include <utility>
#include <vector>

class Programmer;

class Project final {
    friend std::ostream& operator<<(std::ostream& os, const Project& project);
private:
    std::string name_;
public:
    std::vector<std::weak_ptr<Programmer>> programmers_;
    Project(const std::string& name) : name_{ name } {
        std::cout << "Project ctor " << name_ << '\n';
    }

    Project(const Project& other) : name_{ other.name_ } {
        std::cout << "Project copy ctor " << name_ << '\n';
    }

    Project(Project&& other) noexcept {
        std::cout << "Project move ctor for " << other.name_ << '\n';

        name_ = std::move(other.name_);
    }

    Project& operator=(const Project& other) {
        std::cout << "Project assigment for " << other.name_ << '\n';

        name_ = other.name_;
        return *this;
    }

    Project& operator=(Project&& other) {
        std::cout << "Project move assigment for " << other.name_ << '\n';

        name_ = std::move(other.name_);
        return *this;
    }

    ~Project() {
        std::cout << "Project dtor " << name_ << '\n';
    }

    std::string name() {
        return name_;
    }
};

#endif // PAO_CPP_M2_MEMORY_WEAK_PROJECT
