#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<string.h>

int main(){
    void* shared_memory;
    int shmid;

    shmid = shmget((key_t)1234, 1024, 0666);
    printf("shmid : %d\n", shmid);
    shared_memory = shmat(shmid, NULL, 0);
    printf("shared_memory : %p\n",shared_memory);
    printf("Data Read : %s\n", (char*)shared_memory);
}