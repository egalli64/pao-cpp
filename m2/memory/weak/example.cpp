#include <iostream>
#include <memory>
#include <vector>
#include "Programmer.h"
#include "Project.h"

std::ostream& operator<<(std::ostream& os, const Project& project) {
    os << '{' << project.name_;
    os << " [ ";
    for (auto p : project.programmers_) {
        std::shared_ptr<Programmer> sp = p.lock();
        if (sp) {
            os << sp->name() << ' ';
        }
        else {
            os << "Expired programmer ";
        }
    }

    return os << "]}";
}

std::ostream& operator<<(std::ostream& os, const Programmer& programmer) {
    os << '{' << programmer.name_;
    os << " [ ";
    for (auto p : programmer.projects_) {
        std::shared_ptr<Project> sp = p.lock();
        if(sp) {
            os << sp->name() << ' ';
        } else {
            os << "Expired project ";
        }
    }

    return os << "]}";
}

int main() {
    std::vector<std::shared_ptr<Programmer>> programmers;
    programmers.push_back(std::make_shared<Programmer>("Bob"));
    programmers.push_back(std::make_shared<Programmer>("Tom"));
    programmers.push_back(std::make_shared<Programmer>("Kim"));

    std::vector<std::shared_ptr<Project>> projects;
    projects.push_back(std::make_shared<Project>("Delta"));
    projects.push_back(std::make_shared<Project>("Tango"));

    programmers[0]->attachTo(projects[0]);
    projects[0]->add(programmers[0]);

    programmers[1]->attachTo(projects[0]);
    projects[0]->add(programmers[1]);

    programmers[2]->attachTo(projects[1]);
    projects[1]->add(programmers[2]);

    for (const auto p : programmers) {
        std::cout << *p << ' ';
    }
    std::cout << '\n';

    for (const auto p : projects) {
        std::cout << *p << ' ';
    }
    std::cout << '\n';

    projects.erase(projects.begin());

    for (const auto p : programmers) {
        std::cout << *p << ' ';
    }
    std::cout << '\n';

    for (const auto p : projects) {
        std::cout << *p << ' ';
    }
    std::cout << '\n';
}
