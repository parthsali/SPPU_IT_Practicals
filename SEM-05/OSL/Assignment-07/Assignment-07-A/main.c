#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
    int res;
    res = mkfifo("/tmp/myfifo", 0777);

    if(res == -1){
        printf("Error in creating Fifo\n");
        return -1;
    }
    printf("Fifo created\n");
    return 0;
}