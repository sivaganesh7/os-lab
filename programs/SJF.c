#include <stdio.h>

int main() {
    int i, j, n;
    printf("Enter the no of process::");
    scanf("%d", &n);
    int p[n], bt[n], wt[n], tat[n];
    float avgwt = 0, avgtat = 0;

    printf("Enter the burst time of each process::");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        p[i] = i + 1; // Assign process IDs starting from 1
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                // Swap burst times
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap process IDs
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    wt[0] = 0;
    tat[0] = bt[0];
    avgwt += wt[0];
    avgtat += tat[0];

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        avgwt += wt[i];
        avgtat += tat[i];
    }

    printf("Process\tBurst time\tWaiting time\tTurn around time\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);

    printf("Average waiting time::%.2f\n", avgwt / n);
    printf("Average turn around time::%.2f\n", avgtat / n);

    return 0;
}
