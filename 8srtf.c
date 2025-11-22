#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], rt[n], ct[n], tat[n], wt[n];

    for(int i=0;i<n;i++){
        printf("Enter PID, AT, BT: ");
        scanf("%d %d %d",&pid[i],&at[i],&bt[i]);
        rt[i]=bt[i];
    }

    int time=0, completed=0;

    while(completed < n) {
        int idx=-1, minRT=9999;

        for(int i=0;i<n;i++){
            if(at[i] <= time && rt[i] > 0 && rt[i] < minRT){
                minRT = rt[i];
                idx=i;
            }
        }

        if(idx == -1){
            time++;
            continue;
        }

        rt[idx]--;
        time++;

        if(rt[idx]==0){
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            completed++;
        }
    }

    printf("\nPID AT BT CT TAT WT\n");
    for(int i=0;i<n;i++)
        printf("%d  %d  %d  %d  %d  %d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);

    return 0;
}
