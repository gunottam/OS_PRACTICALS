// write.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main() {
    const char *fifoPath = "/tmp/myfifo";
    int fd;

    // Create FIFO if not exists
    if (mkfifo(fifoPath, 0666) == -1) {
        if (errno != EEXIST) {
            perror("mkfifo");
            exit(EXIT_FAILURE);
        }
    }

    char msg[100];

    printf("Enter message to write: ");
    fgets(msg, sizeof(msg), stdin);

    // remove newline at end (optional cleaner display)
    msg[strcspn(msg, "\n")] = '\0';

    int len = strlen(msg);

    // Open FIFO for writing only
    fd = open(fifoPath, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Write data to FIFO
    int written = write(fd, msg, len);
    if (written == -1) {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Write data:%s\n", msg);
    printf("No of bytes:%d\n", written);

    close(fd);
    return 0;
}
