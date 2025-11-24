#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n], done[n];

    for (int i = 0; i < n; i++) {
        printf("Enter PID, AT, BT: ");
        scanf("%d %d %d", &pid[i], &at[i], &bt[i]);
        done[i] = 0;
    }

    int time = 0, completed = 0;

    printf("\n--- GANTT CHART ---\n");
    printf("%d", time);   // starting time

    while (completed < n) {
        int idx = -1, minBT = 9999;

        // find the shortest available job
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && done[i] == 0 && bt[i] < minBT) {
                minBT = bt[i];
                idx = i;
            }
        }

        // CPU idle
        if (idx == -1) {
            time++;
            printf(" --IDLE-- %d", time);
            continue;
        }

        // Execute process
        printf(" --P%d-- ", pid[idx]);

        time += bt[idx];
        printf("%d", time);

        ct[idx]  = time;
        tat[idx] = ct[idx] - at[idx];
        wt[idx]  = tat[idx] - bt[idx];
        done[idx] = 1;
        completed++;
    }

    printf("\n\nPID  AT  BT  CT  TAT  WT\n");
    for (int i = 0; i < n; i++) {
        printf("%d   %d   %d   %d   %d   %d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}