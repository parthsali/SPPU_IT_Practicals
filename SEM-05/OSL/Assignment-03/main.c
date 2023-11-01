#include<stdio.h>


int main(){
    int n;
    printf("Enter the number of processes : ");
    scanf("%d", &n);

    int pno[n], at[n], bt[n], tat[n], wt[n];
    float avg_tat = 0, avg_wt = 0;

    for(int i=0; i<n; i++){
        p[i] = i+1;
        printf("Process %d\n", p[i]);
        printf("Enter the arrival time: ");
        scanf("%d", &at[i]);
        printf("Enter the burst time: ");
        scanf("%d", &bt[i]);
        printf("\n");
    }


    for(int i=0; i<n; i++){
        printf("Process %d\n", i+1);
        printf("Arrival time: %d\n", at[i]);
        printf("Burst time: %d\n", bt[i]);
        printf("\n");
    }
}