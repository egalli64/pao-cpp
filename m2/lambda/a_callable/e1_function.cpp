#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace {
	void print(const std::string& message) {
		std::cout << message << '\n';
	}
}

int main() {
	print("A function is a callable");

	void (*pf)(const std::string&) = &print;
	pf("A pointer to function is commonly used in C");

	std::vector<std::string> names{ "Tom", "Bob", "Kim" };
	std::cout << "Passing a function to another function:\n";
	std::for_each(names.begin(), names.end(), print);
}
