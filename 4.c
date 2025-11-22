#include <stdio.h>
#include <unistd.h>
int main()
{
    int even_sum = 0, odd_sum = 0;
    printf("***OUTPUT***\n");
    pid_t pid = fork();
    if (pid == 0)
    {
        for (int i = 1; i < 10; i += 2)
            odd_sum += i;
        printf("Odd sum is: %d\n", odd_sum);
    }
    else if (pid > 0)
    {
        for (int i = 2; i <= 10; i += 2)
            even_sum += i;
        printf("Even sum is: %d\n", even_sum);
    }
}