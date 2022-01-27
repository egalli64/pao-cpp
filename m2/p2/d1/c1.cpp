#include <iostream>
#include <pthread.h>

using namespace std;

int main() {
    pthread_t id = pthread_self();

    cout << "This thread has id " << id << endl;

    if(pthread_equal(id, id)) {
        cout << "A thread is equal to itself" << endl;
    }
}
