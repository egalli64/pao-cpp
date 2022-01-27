#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

void info(const char* head) {
    cout << head << ": pid " << getpid() << ", tid " << pthread_self() << endl;
}

void* nuller(void*) {
    info("Thread on nuller");
    return nullptr;
}

void* life(void*) {
    info("Thread on life");
    return (void*)42L;
}

void* hanger(void*) {
    info("Thread on hanger");
    pause();
    info("Hanger is back");
    return (void*)99L;
}

int main() {
    pthread_t tids[3];

    {   // create a thread that does not return anything
        int status = pthread_create(&tids[0], nullptr, nuller, nullptr);
        if (status != 0) {
            cout << "Can't create thread 0, error code " << status << endl;
        }
    }

    {   // create a thread that returns a long
        int status = pthread_create(&tids[1], nullptr, life, nullptr);
        if (status != 0) {
            cout << "Can't create thread 1, error code " << status << endl;
        }
    }

    {   // create a thread that hangs
        int status = pthread_create(&tids[2], nullptr, hanger, nullptr);
        if (status != 0) {
            cout << "Can't create thread 2, error code " << status << endl;
        }
    }

    for (int i = 0; i < 2; ++i) {
        void* result;
        pthread_join(tids[i], &result);
        if (result != nullptr) {
            cout << "Thread " << tids[i] << " returned " << reinterpret_cast<long>(result) << endl;
        }
    }

    if (pthread_cancel(tids[2]) != 0) {
        cout << "Can't cancel execution of thread " << tids[2] << endl;
    }
    else {
        cout << "Thread " << tids[2] << " has been canceled " << endl;
    }

    info("Main thread");
}
