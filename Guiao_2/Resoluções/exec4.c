#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
    //Declaração e inicialização de dados 
    int i, s;
    pid_t pid1, pid2;

    for(i = 0; i != 10; i++){
        if(pid1 = fork() == 0){//Criação do filho
            printf("Sou o filho %i, o meu pid e %i e o pid do meu pai e %i\n", i + 1, getpid(), getppid());
            sleep(1);
            printf("Fim da execução de %i\n", getpid());
            _exit(i + 1);
        }
    }
    for(i = 0; i != 10; i++){
        pid2 = wait(&s);
        if(WIFEXITED(s))
            printf("Filho %i terminou com um codigo de saida de %i\n", pid2, WEXITSTATUS(s));
        else    
            puts("Filho nao terminou com exit\n");
    }
    return 0;
}
/*
    Execução concorrente de processos.
    Quando o pai não espera que os filhos morram tambem estamos perante uma execução concorrente de processos
*/
