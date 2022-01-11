/**
 * @file e5.cpp
 * @author Emanuele Galli
 * @brief Parent spawns a child, wait for it, then terminate
 * @version 0.1
 * @date 2022-01-11
 */
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

int main() {
	if (fork() == 0) {
		cout << "Child @work" << endl;
		sleep(1);
		cout << "Child job done" << endl;
		return 0;
	}

	cout << "The parent has spawned the child" << endl;
	int status;
	pid_t pid = wait(&status);

	cout << "Child id " << pid << " has terminated with status " << status << endl;
}
