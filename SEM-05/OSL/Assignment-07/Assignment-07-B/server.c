#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<string.h>

int main(){
    char str[100];
    void *shared_memory; 
    int shmid;

    shmid = shmget((key_t)1234, 1024, 0666|IPC_CREAT);
    printf("shmid : %d\n", shmid);
    shared_memory = shmat(shmid, NULL, 0);
    printf("shared_memory : %p\n", shared_memory);
    printf("Enter Input : \n");

    read(0, str, 100);

    strcpy(shared_memory, str);
    printf("Data Written : %s/n", (char*)shared_memory);
}