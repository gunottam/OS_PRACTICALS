// FCFS CODE

#include <stdio.h>

typedef struct
{
    int pid;
    int at;
    int bt;
    int tat;
    int wt;
    int ct;
} P;

void sortbya(P p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[j].at < p[i].at)
            {
                P t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    P p[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &p[i].pid, &p[i].at, &p[i].bt);
    }

    sortbya(p, n);
    int cp = 0;
    int totwt = 0;
    int tottat = 0;
    int st[n];
    for (int i = 0; i < n; i++)
    {
        int start = (cp > p[i].at) ? cp : p[i].at;

        st[i] = start;

        p[i].ct = start + p[i].bt;
        p[i].wt = start - p[i].at;
        p[i].tat = p[i].ct - p[i].at;
        cp = p[i].ct;

        tottat += p[i].tat;
        totwt += p[i].wt;
    }
    printf("Pid AT BT CT TAT WT");

    for (int i = 0; i < n; i++)
    {
        printf("\nP%d %d %d %d %d %d \n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nGANT CHART\n");
    for (int i = 0; i < n; i++)
    {
        printf(" |%d P%d| ", st[i], p[i].pid);
        for (int j = 0; j < p[i].bt; j++)
            printf(" - ");
    }
    printf("\n");
    return 0;
}