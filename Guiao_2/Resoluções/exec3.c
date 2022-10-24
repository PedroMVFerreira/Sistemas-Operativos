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
        pid2 = wait(&s);
        if(WIFEXITED(s))
            printf("Filho %i terminou com um codigo de saida de %i\n", pid2, WEXITSTATUS(s));
        else    
            puts("Filho nao terminou com exit\n");
        printf("\n\n");
    }
    return 0;
}

/*
    Temos uma criação e execução de programas sequenciais porque o pai espera que o filho morra dentro do ciclo da sua criação, só gerando um novo filho 
*/