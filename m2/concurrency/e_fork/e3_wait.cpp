// Parent spawns a child, wait for it, then terminate
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	if (fork() == 0) {
		std::cout << "Child @work\n";
		sleep(1);
		std::cout << "Child job done\n";
		return 0;
	}

	std::cout << "The parent has spawned its child\n";
	int status;
	pid_t pid = wait(&status);

	std::cout << "Child id " << pid << " has terminated with status " << status << '\n';
}
