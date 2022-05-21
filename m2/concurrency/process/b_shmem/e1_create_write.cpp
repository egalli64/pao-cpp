#include <cstring>
#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

static const key_t SHM_KEY = 0xBAD1DEA;
static int SHM_SEGMENT_SIZE = 1024;

int main() {
	std::cout << "Write 'hello' to shared memory\n";

	// create a shared memory segment with a given key and size
	int shmid = shmget(SHM_KEY, SHM_SEGMENT_SIZE, 0666 | IPC_CREAT);
	if (shmid == -1) {
		std::cerr << "Can't get shared memory\n";
		return 1;
	}

	// attach the shared memory segment to the address space, read/write
	void* pTemp = shmat(shmid, nullptr, 0);
	if (pTemp == (void*)-1) {
		std::cerr << "Can't attach to shared memory\n";
		return 1;
	}
	else { // data transfer
		char* pSharedSegment = static_cast<char*>(pTemp);
		strcpy(pSharedSegment, "hello");
	}

	// detach
	shmdt(pTemp);
}
