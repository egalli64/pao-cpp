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
        if (sp) {
            os << sp->name() << ' ';
        }
        else {
            os << "Expired project ";
        }
    }

    return os << "]}";
}

namespace {
    void link(std::shared_ptr<Programmer> programmer, std::shared_ptr<Project> project) {
        std::cout << programmer->name() << " -> " << project->name() << '\n';
        programmer->attachTo(project);
        project->add(programmer);
    }

    void dump(const std::vector<std::shared_ptr<Programmer>>& programmers) {
        for (const auto programmer : programmers) {
            std::cout << *programmer << ' ';
        }
        std::cout << '\n';
    }

    void dump(const std::vector<std::shared_ptr<Project>>& projects) {
        for (const auto project : projects) {
            std::cout << *project << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    std::vector<std::shared_ptr<Programmer>> programmers;
    programmers.push_back(std::make_shared<Programmer>("Bob"));
    programmers.push_back(std::make_shared<Programmer>("Tom"));
    programmers.push_back(std::make_shared<Programmer>("Kim"));

    std::vector<std::shared_ptr<Project>> projects;
    projects.push_back(std::make_shared<Project>("Delta"));
    projects.push_back(std::make_shared<Project>("Tango"));

    dump(programmers);
    dump(projects);

    link(programmers[0], projects[0]);
    link(programmers[1], projects[0]);
    link(programmers[2], projects[1]);

    dump(programmers);
    dump(projects);

    projects.erase(projects.begin());

    dump(programmers);
    dump(projects);
}
