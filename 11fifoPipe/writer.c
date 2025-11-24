#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    char msg[100];

    mkfifo("myfifo", 0666);

    printf("Enter message: ");
    fgets(msg, sizeof(msg), stdin);

    int fd = open("myfifo", O_WRONLY);
    write(fd, msg, sizeof(msg));

    printf("Message written: %s\n", msg);

    close(fd);
    return 0;
}
