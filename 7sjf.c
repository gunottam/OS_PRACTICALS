#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n], done[n];

    for(int i=0;i<n;i++){
        printf("Enter PID, AT, BT: ");
        scanf("%d %d %d",&pid[i],&at[i],&bt[i]);
        done[i]=0;
    }

    int time=0, completed=0;

    while(completed < n) {
        int idx=-1, minBT=9999;

        // find shortest available process
        for(int i=0;i<n;i++){
            if(at[i] <= time && done[i]==0 && bt[i] < minBT){
                minBT = bt[i];
                idx = i;
            }
        }

        if(idx == -1) { 
            time++; 
            continue; 
        }

        time += bt[idx];
        ct[idx] = time;
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];
        done[idx] = 1;
        completed++;
    }

    printf("\nPID AT BT CT TAT WT\n");
    for(int i=0;i<n;i++)
        printf("%d  %d  %d  %d  %d  %d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);

    return 0;
}
