#include <stdio.h>

int main() {
    int pages[50], frame[100], n, f, i, j, k, flag, faults=0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page sequence: ");
    for(i=0;i<n;i++)
        scanf("%d",&pages[i]);

    printf("Enter number of frames: ");
    scanf("%d",&f);

    for(i=0;i<f;i++)
        frame[i] = -1;

    k = 0;

    for(i=0;i<n;i++){
        flag = 0;

        for(j=0;j<f;j++){
            if(frame[j] == pages[i]){
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            frame[k] = pages[i];
            k = (k+1) % f;
            faults++;
        }
    }

    printf("\nPage Faults: %d\n", faults);
    return 0;
}
