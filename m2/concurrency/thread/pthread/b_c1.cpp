#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void info(const char* head) {
    pthread_mutex_lock(&lock);
    cout << head << ": pid " << getpid() << ", tid " << pthread_self() << endl;
    pthread_mutex_unlock(&lock);
}

void* messenger(void*) {
    info("Hello from");
    return nullptr;
}

int main() {
    pthread_t tids[10];

    for (int i = 0; i < 10; ++i) {
        int status = pthread_create(&tids[i], nullptr, messenger, nullptr);
        if (status != 0) {
            cout << "Can't create thread 0, error code " << status << endl;
        }
    }

    for (int i = 0; i < 10; ++i) {
        pthread_join(tids[i], nullptr);
    }
}
