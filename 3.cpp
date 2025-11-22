#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("***OUTPUT***\n");
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("Hello from child!: %d\n", getpid());
    }
    else if (pid > 0)
    {
        printf("Hello from parent!: %d\n", getppid());
    }
    else
    {
        printf("failed!!\n");
    }
}
