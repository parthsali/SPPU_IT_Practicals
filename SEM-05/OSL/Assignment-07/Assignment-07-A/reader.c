#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

// Function to count the number of characters in a string
int countChars(char *str){
    int i=0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

// Function to count the number of words in a string
int countWords(char *str){
    
    int i=0, count=0;
    while(1){
        if(str[i] == '\0'){
            printf("End of string\n");
            break;
        }

        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
            count++;

        i++;
        printf("%c\n", str[i]);
    }
    printf("Count: %d\n", count);
    return count;
}




int main(){
    // str is the buffer to store the input from the fifo file
    char str[100];


    
    while(1){
        // Open the fifo file in read only mode which is already created by the main.c program
        // /tmp/myfifo is the name of the fifo file
        // fd is the file descriptor for the fifo file
        // if fd is -1, then fifo file is not opened
        // if fd is 0, then fifo file is opened
        int fd = open("/tmp/myfifo", O_RDONLY);

        // read the input from the fifo file and store it in the buffer str
        // read function accepts the file descriptor, buffer, and number of bytes to read as arguments
        read(fd, str, sizeof(str));

        // fd1 is the file descriptor for the output.txt file
        // fopen function accepts the name of the file and mode as arguments
        // if file does not exist, then it is created and opened in the specified mode( in this case, write mode)
        FILE* fd1 = fopen("output.txt", "w");

        // Check if file is opened successfully
        // if fd1 is NULL, then file is not opened
        if(fd1 == NULL){
            printf("Error opening file\n");
            return -1; 
        }
        
        // fprintf function accepts the file pointer and the string to write as arguments
        // fprintf writes the string to the file
        fprintf(fd1, "String: %s\n", str);
        fprintf(fd1,"Number of characters: %d\n", countChars(str));
        fprintf(fd1, "Number of words: %d\n", countWords(str));
        
        // close the text file
        fclose(fd1);

        // close the fifo file
        close(fd);
    }
    return 0;
}