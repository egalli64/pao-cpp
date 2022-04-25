#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void info(const char* head) {
    cout << head << ": pid " << getpid() << ", tid " << pthread_self() << endl;
}

void* mistake(void*) {
    pthread_mutex_lock(&lock);
    info("So far so good");

    pthread_mutex_lock(&lock);
    info("Won't get here");

    pthread_mutex_unlock(&lock);
    pthread_mutex_unlock(&lock);

    return nullptr;
}

int main() {
    pthread_t tid;

    int status = pthread_create(&tid, nullptr, mistake, nullptr);
    if (status != 0) {
        cout << "Can't create thread 0, error code " << status << endl;
    }

    sleep(1);
    
    if (pthread_cancel(tid) != 0) {
        cout << "Can't cancel execution of thread " << tid << endl;
    }
    else {
        cout << "Thread " << tid << " has been canceled " << endl;
    }
}
