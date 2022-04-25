#include <ctime>
#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

static pthread_mutex_t lock_timed = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t lock_plain = PTHREAD_MUTEX_INITIALIZER;

void infoAtTime(const char* head) {
    pthread_mutex_lock(&lock_plain);
    cout << head << ": pid " << getpid() << ", tid " << pthread_self() << " @time " << time(nullptr) << endl;
    pthread_mutex_unlock(&lock_plain);
}

void* timed(void*) {
    timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    ts.tv_sec += 1;

    infoAtTime("Acquiring lock");
    if (pthread_mutex_timedlock(&lock_timed, &ts) == ETIMEDOUT) {
        infoAtTime("No lock");
    }
    else {
        infoAtTime("Lock acquired");

        sleep(2);
        pthread_mutex_unlock(&lock_timed);
        infoAtTime("Lock freed");
    }

    return nullptr;
}

int main() {
    pthread_t tids[2];

    for (int i = 0; i < 2; ++i) {
        int status = pthread_create(&tids[i], nullptr, timed, nullptr);
        if (status != 0) {
            cout << "Can't create thread " << i << ", error code " << status << endl;
        }
    }

    sleep(3);

    infoAtTime("Main done");
}
