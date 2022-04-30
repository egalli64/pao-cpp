#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
	auto print = [] (const std::string& message) {
		std::cout << message << '\n';
	};
	print("A lambda is a callable");

	std::vector<std::string> names{ "Tom", "Bob", "Kim" };
	std::cout << "Passing a lambda to a function:\n";
	std::for_each(names.begin(), names.end(), print);
}
