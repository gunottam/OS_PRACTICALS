#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg {
    long type;
    char text[100];
};

int main() {
    key_t key = ftok("msgfile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    struct msg m;
    m.type = 1;

    printf("Enter message: ");
    fgets(m.text, sizeof(m.text), stdin);

    msgsnd(msgid, &m, sizeof(m.text), 0);

    printf("Message sent.\n");
    return 0;
}
