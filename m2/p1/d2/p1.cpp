#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main() {
    int pds[2];

    if (pipe(pds)) {
        cout << "Can't create pipe" << endl;
        return 1;
    }

    int pid = fork();
    if (pid < 0) {
        cout << "Can't fork" << endl;
        return 2;
    }
    else if (pid > 0) { // parent
        close(pds[0]);

        string message{ "hello world" };
        write(pds[1], message.c_str(), message.size());
    }
    else { // child
        close(pds[1]);

        const int SZ = 80;
        char buffer[SZ + 1];
        int n = read(pds[0], buffer, SZ);
        buffer[n] = '\0';

        cout << buffer << endl;
    }
}