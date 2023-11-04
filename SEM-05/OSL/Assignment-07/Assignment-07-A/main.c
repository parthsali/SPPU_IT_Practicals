// Name : Parth Sali.
// Roll No. : 33166

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
    // res is file descriptor for the fifo file
    int res;

    // Create a fifo file with name /tmp/myfifo and permissions 0777
    // 0777 means that the fifo file will have read, write, and execute permissions for the user, group, and others
    res = mkfifo("/tmp/myfifo", 0777);

    // Check if fifo file is created successfully
    // if res is -1, then fifo file is not created
    // if res is 0, then fifo file is created
    if(res == -1){
        printf("Error in creating Fifo\n");
        return -1;
    }

    printf("Fifo created\n");
    return 0;
}