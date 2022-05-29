#include <unistd.h>
#include <iostream>

int main() {
	std::cout << "This process ID: " << getpid() << '\n';
	std::cout << "The parent process ID: " << getppid() << '\n';
}
