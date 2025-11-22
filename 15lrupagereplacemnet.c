#include <stdio.h>

int main() {
    int pages[50], frame[10], used[10];
    int n, f, i, j, k, flag, faults=0, least;

    printf("Enter number of pages: ");
    scanf("%d",&n);

    printf("Enter page sequence: ");
    for(i=0;i<n;i++)
        scanf("%d",&pages[i]);

    printf("Enter number of frames: ");
    scanf("%d",&f);

    for(i=0;i<f;i++){
        frame[i] = -1;
        used[i] = -1;
    }

    for(i=0;i<n;i++){
        flag = 0;

        for(j=0;j<f;j++){
            if(frame[j] == pages[i]){
                flag = 1;
                used[j] = i;
                break;
            }
        }

        if(flag == 0){
            int idx = 0;
            for(j=1;j<f;j++)
                if(used[j] < used[idx]) idx = j;

            frame[idx] = pages[i];
            used[idx] = i;
            faults++;
        }
    }

    printf("\nPage Faults: %d\n", faults);
    return 0;
}
