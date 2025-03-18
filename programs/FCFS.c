#include<stdio.h>

int main() {
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];
    float avgwt = 0, avgtat = 0;

    printf("Enter the burst time for %d processes:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }
    wt[0] = 0; 
    tat[0] = bt[0];  
    avgwt += wt[0];
    avgtat += tat[0];
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1]; 
        tat[i] = wt[i] + bt[i]; 
        avgwt += wt[i];
        avgtat += tat[i];
    }

    
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
    }
    printf("Average Waiting Time: %.2f\n", avgwt / n);
    printf("Average Turnaround Time: %.2f\n", avgtat / n);

    return 0;
}
