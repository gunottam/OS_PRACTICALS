#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);

    int pid = fork();

    if(pid > 0) { 
        // Parent writes
        close(fd[0]);
        char msg[50];
        printf("Enter message: ");
        fgets(msg, sizeof(msg), stdin);
        write(fd[1], msg, sizeof(msg));
        close(fd[1]);
    } 
    else { 
        // Child reads
        close(fd[1]);
        char buffer[50];
        read(fd[0], buffer, sizeof(buffer));
        printf("\nReceived: %s", buffer);
        close(fd[0]);
    }

    return 0;
}
