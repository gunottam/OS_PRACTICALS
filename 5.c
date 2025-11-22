#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    printf("***OUTPUT***\n");
    pid_t pid = fork();
    if (pid == 0)
        printf("Child Process!\n");
    else if (pid > 0)
    {
        wait(NULL);
        printf("this is parent with PID: %d\n", getppid());
    }
}