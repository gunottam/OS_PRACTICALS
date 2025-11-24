#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], rt[n], ct[n], tat[n], wt[n];

    for(int i = 0; i < n; i++) {
        printf("Enter PID, AT, BT: ");
        scanf("%d %d %d", &pid[i], &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    int time = 0, completed = 0;
    int prev = -1;  // previous running process (for neat Gantt chart)

    printf("\n--- GANTT CHART ---\n");
    printf("%d", time);

    while (completed < n) {

        int idx = -1, minRT = 9999;

        // select shortest remaining time process
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && rt[i] < minRT) {
                minRT = rt[i];
                idx = i;
            }
        }

        // CPU idle
        if (idx == -1) {
            if (prev != -2) {  // print idle once
                printf(" --IDLE-- ");
                prev = -2;
            }
            time++;
            printf("%d", time);
            continue;
        }

        // If process changes, print it
        if (idx != prev) {
            printf(" --P%d-- ", pid[idx]);
            prev = idx;
        }

        // Execute 1 unit
        rt[idx]--;
        time++;
        printf("%d", time);

        // Process completed
        if (rt[idx] == 0) {
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            completed++;
        }
    }

    printf("\n\nPID  AT  BT  CT  TAT  WT\n");
    for (int i = 0; i < n; i++) {
        printf("%d   %d   %d   %d   %d   %d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}