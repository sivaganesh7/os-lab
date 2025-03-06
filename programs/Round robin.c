#include<stdio.h>

int main() {
    int i, j, n, bu[10], wa[10], tat[10], ct[10], max;
    float awt = 0, att = 0;
    int time_slice;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst time for each process
    for(i = 0; i < n; i++) {
        printf("\nEnter burst time for process %d: ", i + 1);
        scanf("%d", &bu[i]);
        ct[i] = bu[i];  // Store original burst time
    }

    // Input time slice
    printf("\nEnter the size of time slice: ");
    scanf("%d", &time_slice);

    // Find maximum burst time
    max = bu[0];
    for(i = 1; i < n; i++) {
        if(max < bu[i]) {
            max = bu[i];
        }
    }

    // Round Robin scheduling
    int temp = 0;  // Current time
    for(j = 0; j < (max/time_slice) + 1; j++) {
        for(i = 0; i < n; i++) {
            if(bu[i] != 0) {
                if(bu[i] <= time_slice) {
                    temp += bu[i];
                    tat[i] = temp;  // Turnaround time = completion time
                    bu[i] = 0;
                } else {
                    bu[i] -= time_slice;
                    temp += time_slice;
                }
            }
        }
    }

    // Calculate waiting time and averages
    for(i = 0; i < n; i++) {
        wa[i] = tat[i] - ct[i];  // Waiting time = Turnaround time - Burst time
        att += tat[i];
        awt += wa[i];
    }

    // Print results in a formatted table
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    printf("------------------------------------------------\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i+1, ct[i], wa[i], tat[i]);
    }
    
    // Print averages
    printf("\nAverage Turnaround Time: %.2f", att/n);
    printf("\nAverage Waiting Time: %.2f\n", awt/n);

    return 0;
}
