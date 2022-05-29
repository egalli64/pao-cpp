#include <cstring>
#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

namespace {
	const key_t SHM_KEY = 0xBAD1DEA;
	const int SHM_SEGMENT_SIZE = 1'024;
}

int main() {
	std::cout << "Read from shared memory\n";

	// access a shared memory segment with a given key and size
	int shmid = shmget(SHM_KEY, SHM_SEGMENT_SIZE, 0666);
	if (shmid == -1) {
		std::cerr << "Can't get shared memory\n";
		return EXIT_FAILURE;
	}

	// attach the shared memory segment to the address space, read only
	void* attachedMemory = shmat(shmid, nullptr, SHM_RDONLY);
	if (attachedMemory == (void*)-1) {
		std::cerr << "Can't attach to shared memory\n";
		attachedMemory = nullptr;

		return EXIT_FAILURE;
	}
	else { // access the data
		char* pSharedSegment = static_cast<char*>(attachedMemory);
		std::cout << pSharedSegment << '\n';
	}

	if (shmdt(attachedMemory) == -1) {
		std::cerr << "Can't detach the shared memory segment\n";
	}
	if (shmctl(shmid, IPC_RMID, nullptr) == -1) {
		std::cerr << "Can't remove the shared memory segment\n";
	}
}
