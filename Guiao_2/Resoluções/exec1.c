#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
    printf("Sou um processo e o meu pid e: %d e o meu pai tem o pid de: %d\n\n\n", getpid(), getppid());
    return 0;
}