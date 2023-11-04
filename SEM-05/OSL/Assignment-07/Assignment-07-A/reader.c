#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>


int countChars(char *str){
    int i=0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

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
    char str[100];

    while(1){
        int fd = open("/tmp/myfifo", O_RDONLY);

        read(fd, str, sizeof(str));

        FILE* fd1 = fopen("output.txt", "w");
        if(fd1 == NULL){
            printf("Error opening file\n");
            return -1; 
        }

        fprintf(fd1, "String: %s\n", str);
        fprintf(fd1,"Number of characters: %d\n", countChars(str));
        fprintf(fd1, "Number of words: %d\n", countWords(str));
        
        fclose(fd1);

        close(fd);
    }
    return 0;
}