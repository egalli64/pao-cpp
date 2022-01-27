#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

static pthread_mutex_t lock_1 = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t lock_2 = PTHREAD_MUTEX_INITIALIZER;

void info(const char* head) {
    cout << head << ": pid " << getpid() << ", tid " << pthread_self() << endl;
}

void* mistake_1(void*) {
    pthread_mutex_lock(&lock_1);
    info("First lock acquired");

    sleep(1);
    pthread_mutex_lock(&lock_2);
    info("Won't get here");

    pthread_mutex_unlock(&lock_2);
    pthread_mutex_unlock(&lock_1);

    return nullptr;
}

void* mistake_2(void*) {
    pthread_mutex_lock(&lock_2);
    info("Second lock acquired");

    sleep(1);
    pthread_mutex_lock(&lock_1);
    info("Won't get here");

    pthread_mutex_unlock(&lock_1);
    pthread_mutex_unlock(&lock_2);

    return nullptr;
}

int main() {
    pthread_t tids[2];

    int status = pthread_create(&tids[0], nullptr, mistake_1, nullptr);
    if (status != 0) {
        cout << "Can't create thread 0, error code " << status << endl;
    }

    status = pthread_create(&tids[1], nullptr, mistake_2, nullptr);
    if (status != 0) {
        cout << "Can't create thread 1, error code " << status << endl;
    }

    sleep(2);

    for (int i = 0; i < 2; ++i) {
        cout << "Thread " << tids[i];
        if (pthread_cancel(tids[i]) != 0) {
            cout << " can't be canceled" << endl;
        }
        else {
            cout << " has been canceled " << endl;
        }
    }
}
