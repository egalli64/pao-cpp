#include <unistd.h>
#include <iostream>
using namespace std;

int main() {
	cout << "This process id: " << getpid() << endl;
	cout << "The parent process id: " << getppid() << endl;
}
