// Name : Parth Sali
// Roll No. : 33166

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<string.h>

int main(){
    // shared_memory is the pointer to the shared memory (address)
    void* shared_memory;

    // shmid is the shared memory id
    int shmid;

    // Create a shared memory segment having key 1234, size 1024 bytes, and permissions 0666 (Key should be same for both client and server)
    shmid = shmget((key_t)1234, 1024, 0666);
    printf("shmid : %d\n", shmid);

    // Attach the shared memory segment to the address space of the calling process (client.c)
    // shmat accepts the shmid, address to attach, and flags (0) as arguments
    // null indicates that the system will choose a suitable (unused) address to attach the shared memory segment. (we can specify the address also)
    // flag 0 indicates that the shared memory segment is read and write
    shared_memory = shmat(shmid, NULL, 0);

    // Print the address of the shared memory segment
    printf("shared_memory : %p\n",shared_memory);

    // Print the data written to the shared memory segment.
    printf("Data Read : %s\n", (char*)shared_memory);
}

