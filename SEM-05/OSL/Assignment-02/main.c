#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter the number of integers to be sorted: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the integers to be sorted: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    pid_t pid = fork();
    if (pid == 0) {
        // child process
        printf("Child process sorting the integers using bubble sort algorithm...\n");
        bubbleSort(arr, n);
        printf("Sorted integers by child process: ");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else if (pid > 0) {
        // parent process
        printf("Parent process waiting for child process to complete...\n");
        wait(NULL);
        printf("Sorted integers by parent process: ");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        // fork failed
        printf("Fork failed!\n");
        return 1;
    }
    return 0;
}

