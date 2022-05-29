#include <iostream>
#include <sys/types.h>
#include <unistd.h>

int main() {
	pid_t pid = getpid();
	std::cout << "Process ID " << pid << '\n';

	// spawn a child
	pid_t fid = fork();
	std::cout << "Fork returns negative (error), zero or child ID: " << fid << '\n';

	if (fid < 0) {
		std::cout << "Unexpected, can't fork process\n";
		return 1;
	}

	if (fid == 0) {
		std::cout << "In child process " << getpid() << " parent " << getppid() << '\n';
	}
	else {
		std::cout << "In main process " << getpid() << " child " << fid << " parent " << getppid() <<  '\n';
	}
}
