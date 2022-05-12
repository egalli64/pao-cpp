#include <unistd.h>
#include <iostream>

int main() {
	std::cout << "This process id: " << getpid() << '\n';
	std::cout << "The parent process id: " << getppid() << '\n';
}
