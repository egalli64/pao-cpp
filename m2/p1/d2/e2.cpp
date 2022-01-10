#include <iostream>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

int main() {
	pid_t pid = getpid();
	cout << "Process id " << pid << endl;

	pid_t fid = fork();
	cout << "Fork returns " << fid << endl;

	if (fid < 0) {
		return 1;
	}

	if (fid == 0) {
		cout << "Child pid " << getpid() << " parent id " << getppid() << endl;
	}
	else {
		cout << "Original pid " << getpid() << " parent id " << getppid() << endl;
	}
}
