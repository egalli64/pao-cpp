#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void f(const std::string& message) {
	std::cout << message << '\n';
}

int main() {
	f("A function is a callable");

	void (*pf)(const std::string&) = &f;
	pf("A pointer to function is commonly used in C");

	std::vector<std::string> names{ "Tom", "Bob", "Kim" };
	std::cout << "Passing a function to another function:\n";
	std::for_each(names.begin(), names.end(), f);
}
