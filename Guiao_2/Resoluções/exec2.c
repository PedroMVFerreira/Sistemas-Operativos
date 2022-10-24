#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
    pid_t pid = fork(); //Criação de um processo filho 
    switch(pid){
        case -1:    //Não foi possivel criar um processo filho
            perror("FORK");
        return -1;
        case 0: //filho
            printf("Sou um processo filho e o meu pid e: %d e o meu pai tem o pid de: %d\n", getpid(), getppid());
        break;
        default: //pai
            printf("Sou um processo pai o meu pid e: %d o pid do meu pai e: %d e o pid do filho e: %d\n", getpid(), getppid(), pid);
        break;
    }
    return 0;
}
