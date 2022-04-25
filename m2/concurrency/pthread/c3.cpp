#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

static pthread_mutex_t lock_1 = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t lock_2 = PTHREAD_MUTEX_INITIALIZER;

void info(const char* head) {
    cout << head << ": pid " << getpid() << ", tid " << pthread_self() << endl;
}

void* ordered(void*) {
    pthread_mutex_lock(&lock_1);
    info("First lock acquired");

    sleep(1);
    pthread_mutex_lock(&lock_2);
    info("Second lock acquired");

    pthread_mutex_unlock(&lock_2);
    pthread_mutex_unlock(&lock_1);

    return nullptr;
}

int main() {
    pthread_t tids[2];

    for(int i = 0; i < 2; ++i) {
        int status = pthread_create(&tids[i], nullptr, ordered, nullptr);
        if (status != 0) {
            cout << "Can't create thread " << i << ", error code " << status << endl;
        }
    }

    sleep(3);

    info("Main done");
}
