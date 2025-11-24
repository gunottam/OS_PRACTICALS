#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    char buffer[100];

    mkfifo("myfifo", 0666);

    int fd = open("myfifo", O_RDONLY);
    read(fd, buffer, sizeof(buffer));

    printf("Message read: %s\n", buffer);

    close(fd);
    return 0;
}
