#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main() {
    int fd[2];  // fd[0] = read end, fd[1] = write end

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // Parent Process (Writer)
    if (pid > 0) {
        close(fd[0]);  // close read end

        char msg[100];

        printf("Enter message to send: ");
        if (fgets(msg, sizeof(msg), stdin) == NULL) {
            perror("fgets");
            close(fd[1]);
            exit(EXIT_FAILURE);
        }

        // remove trailing newline if present
        msg[strcspn(msg, "\n")] = '\0';

        int len = strlen(msg);

        // Write to pipe
        int written = write(fd[1], msg, len);
        if (written == -1) {
            perror("write");
            close(fd[1]);
            exit(EXIT_FAILURE);
        }

        printf("Write data:%s\n", msg);
        printf("No of bytes:%d\n", written);

        close(fd[1]);
    }
    // Child Process (Reader)
    else {
        close(fd[1]);  // close write end

        char buffer[100];
        int n = read(fd[0], buffer, sizeof(buffer)-1);
        if (n == -1) {
            perror("read");
            close(fd[0]);
            exit(EXIT_FAILURE);
        }

        buffer[n] = '\0';

        printf("Message Written:%s\n", buffer);
        printf("No of bytes:%d\n", n);

        close(fd[0]);
    }

    return 0;
}
