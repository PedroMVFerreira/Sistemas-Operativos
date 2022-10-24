#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
    //Declaração de dados 
    int i; 
    for(i = 0; i != 10; i++){
        if(fork())
            _exit(0);
        printf("Sou o processo: %i. O meu pid e: %i e o pid do meu pai e: %i\n", i + 1,  getpid(), getppid());
    }
    return 0;
}