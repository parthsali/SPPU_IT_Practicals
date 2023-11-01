#include<stdio.h>

int np, nr;
int allocation[10][10], max[10][10], need[10][10];
int available[10];
int safeSequence[10];
int completed[10];

void input(int matrix[10][10]){
    for(int i=0; i<np; i++){
        for(int j=0; j<nr; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
}

void calculateNeed(){
    for(int i=0; i<np; i++){
        for(int j=0; j < nr; j++){
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

void printMatrix(int matrix[10][10]){
    for(int i=0; i<np; i++){
        for(int j=0; j<nr; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    printf("Enter Number of Processes : ");
    scanf("%d", &np);
    printf("Enter Number of Resources : ");
    scanf("%d", &nr);

    printf("Enter Allocation Matrix : ");
    input(allocation);

    printf("Enter Max Matrix : ");
    input(max);

    printf("Enter Available Matrix : ");
    for(int i=0; i<nr; i++){
        scanf("%d", &available[i]);
    }

    calculateNeed();

    printf("Allocation Matrix : \n");
    printMatrix(allocation);

    printf("Max Matrix : \n");
    printMatrix(max);

    printf("Need Matrix : \n");
    printMatrix(need);

    printf("Available Matrix : \n");
    for(int i=0; i<nr; i++){
        printf("%d ", available[i]);
        
    }
    printf("\n");
    printf("Safe Sequence : \n");

    int flag = 0;

    for(int i=0; i<np; i++){
        completed[i] = 0;
        printf("Completed 0");
    } 

    printf("Inside for loop");

    for(int i=0; i < np; i++){
        printf("Inside for loop");
        if(completed[i] == 0){
            for(int j=0; j<nr; j++){
                if(need[i][j] > available[j]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                for(int j=0; j<nr; i++){
                    available[i] += allocation[i][j];
                }
                safeSequence[i] = i;
                completed[i] = 1;
            }

        }
    }
    flag = 0;
    for(int i=0; i<np; i++){
        if(completed[i] == 0){
            printf("System is not in safe state\n");
            flag = 1;
            break;
        }
    }

    if(flag == 0){
        printf("System is in safe state\n");
        printf("Safe Sequence : ");
        for(int i=0; i<np; i++){
            printf("%d ", safeSequence[i]);
        }
        printf("\n");
    }






}