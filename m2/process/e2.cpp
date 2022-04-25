#include <iostream>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

int main() {
	pid_t pid = getpid();
	cout << "Process id " << pid << endl;

	pid_t fid = fork();
	cout << "Fork returns negative (error), zero or child id: " << fid << endl;

	if (fid < 0) {
		return 1;
	}

	if (fid == 0) {
		cout << "In child process " << getpid() << " parent " << getppid() << endl;
	}
	else {
		cout << "In main process " << getpid() << " child " << fid << " parent " << getppid() <<  endl;
	}
}
