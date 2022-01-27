#include <iostream>
#include <signal.h>
#include <unistd.h>

using namespace std;

static int my_internal_status = 0;

void signal_manager(int id) {
    switch (id) {
    case SIGUSR1:
        cout << "SIGUSR1 trapped" << endl;
        my_internal_status += 1;
        break;
    case SIGUSR2:
        cout << "SIGUSR2 trapped" << endl;
        my_internal_status += 2;
        break;
    default:
        cout << "signal " << id << " was not expected!" << endl;
        break;
    }
}

int main() {
    if (signal(SIGUSR1, signal_manager) == SIG_ERR) {
        cout << "Can't manage SIGUSR1!" << endl;
        return 1;
    }
    if (signal(SIGUSR2, signal_manager) == SIG_ERR) {
        cout << "Can't manage SIGUSR1!" << endl;
        return 1;
    }

    cout << "\nSIGINT (" << SIGINT << ") is for terminal interrupt character" << endl;
    cout << "SIGUSR1 and SIGUSR2 (" << SIGUSR1 << ", " << SIGUSR2
        << ") are for user-defined signals, by default terminate the app, here are trapped" << endl;

    while (true) {
        pause();
        cout << "\nA signal awakened the process, status is " << my_internal_status << endl;
    }
}
