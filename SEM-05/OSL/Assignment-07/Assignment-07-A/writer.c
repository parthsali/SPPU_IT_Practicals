#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    // arr is the buffer to store the input from the user
    char arr[100];
    while(1){
        // Open the fifo file in write only mode which is already created by the main.c program
        int fd = open("/tmp/myfifo", O_WRONLY);


        printf("Enter a string: ");

        // Take input from the user and store it in the buffer arr.
        // fgets function accepts the buffer, number of bytes to read, and the input stream(stdin) as arguments.
        fgets(arr, 100, stdin);

        // Print the input taken from the user
        printf("Writer: %s\n", arr);
        
        // write the input to the fifo file
        // write function accepts the file descriptor, buffer, and number of bytes to write as arguments
        write(fd, arr, sizeof(arr));

        // close the fifo file
        close(fd);
    }
    return 0;
}