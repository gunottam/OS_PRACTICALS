#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("***OUTPUT***\n");
    fork();
    printf("Hello !\n");
    fork();
    printf("World!!\n");
}
