// reader.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main() {
    const char *fifoPath = "/tmp/myfifo";
    int fd;

    // Ensure FIFO exists (optional but safe)
    if (mkfifo(fifoPath, 0666) == -1) {
        if (errno != EEXIST) {
            perror("mkfifo");
            exit(EXIT_FAILURE);
        }
    }

    // Open FIFO for reading
    fd = open(fifoPath, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    char buffer[100];
    int n = read(fd, buffer, sizeof(buffer) - 1);
    if (n == -1) {
        perror("read");
        close(fd);
        exit(EXIT_FAILURE);
    }

    buffer[n] = '\0';  // null-terminate

    printf("Message Written:%s\n", buffer);
    printf("No of bytes:%d\n", n);

    close(fd);
    return 0;
}
