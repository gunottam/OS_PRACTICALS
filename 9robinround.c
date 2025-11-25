#include <stdio.h>

int main() {
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int pid[n], at[n], bt[n], rt[n], ct[n], tat[n], wt[n];

    for(int i = 0; i < n; i++) {
        printf("Enter PID, AT, BT: ");
        scanf("%d %d %d", &pid[i], &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    int time = 0, completed = 0;
    int idlePrinted = 0;

    printf("\n--- GANTT CHART ---\n");
    printf("%d", time);

    while(completed < n) {
        int executed = 0;

        for(int i = 0; i < n; i++) {

            if(at[i] <= time && rt[i] > 0) {

                executed = 1;

                // Print process in Gantt chart
                printf(" --P%d-- ", pid[i]);

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } 
                else {
                    time += rt[i];
                    rt[i] = 0;

                    // completion & time calculations
                    ct[i]  = time;
                    tat[i] = ct[i] - at[i];
                    wt[i]  = tat[i] - bt[i];
                    completed++;
                }

                // print current time
                printf("%d", time);

                idlePrinted = 0; 
            }
        }

        // No process executed → CPU idle
        if(!executed) {
            if(!idlePrinted) {
                printf(" --IDLE-- ");
                idlePrinted = 1;
            }
            time++;
            printf("%d", time);
        }
    }

    printf("\n\nPID  AT  BT  CT  TAT  WT\n");
    for(int i = 0; i < n; i++) {
        printf("%d   %d   %d   %d   %d   %d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}