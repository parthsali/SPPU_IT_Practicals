#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
    pid_t pid = fork();

    if(pid == 0){
        sleep(5);
        printf("This is Child Process having id : %d\n", getpid());
        printf("This is Child Process having Parent id : %d\n", getppid());
    }
    else{
        
        printf("This is Parent Process having id : %d\n", getpid());
        printf("This is Parent Process having child id : %d\n", pid );
    }
    return 0;
}