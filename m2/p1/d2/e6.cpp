/**
 * @file e6.cpp
 * @author Emanuele Galli
 * @brief Private memory shared between child (client) and parent (server)
 * @version 0.1
 * @date 2022-01-11
 */
#include <cstring>
#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

static int SHM_SEGMENT_SIZE = 1024;
static void* attachedMemory = nullptr;

int main() {
	cout << "The parent creates a private shm segment" << endl;
	int shmid = shmget(IPC_PRIVATE, SHM_SEGMENT_SIZE, 0644 | IPC_CREAT);
	if (shmid == -1) {
		cerr << "Can't get shared memory" << endl;
		return 1;
	}

	// attach the shared memory segment to the address space, read/write
	attachedMemory = shmat(shmid, nullptr, 0);
	if (attachedMemory == (void*)-1) {
		cerr << "Can't attach to shared memory" << endl;
		return 2;
	}
	else { // data transfer
		char* pSharedSegment = static_cast<char*>(attachedMemory);
		strcpy(pSharedSegment, "welcome back!");
	}

	if (fork() == 0) {
		cout << "Child @work" << endl;
		sleep(1);

		const char* pSharedSegment = static_cast<const char*>(attachedMemory);
		cout << pSharedSegment << endl;

		return 0;
	}

	cout << "The parent has spawned the child" << endl;
	int status;
	pid_t pid = wait(&status);
	cout << "Child id " << pid << " has terminated with status " << status << endl;

	if (shmdt(attachedMemory) == -1) {
		cout << "Can't detach the shared memory segment" << endl;
	}
	if (shmctl(shmid, IPC_RMID, nullptr) == -1) {
		cout << "Can't remove the shared memory segment" << endl;
	}
}
