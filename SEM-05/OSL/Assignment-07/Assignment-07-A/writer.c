#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    char arr[100];
    while(1){
        int fd = open("/tmp/myfifo", O_WRONLY);

        printf("Enter a string: ");
        fgets(arr, 100, stdin);
        printf("Writer: %s\n", arr);

        write(fd, arr, sizeof(arr));
        close(fd);
    }
    return 0;
}