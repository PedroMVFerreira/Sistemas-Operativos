//Exercicio: O processo pai deverá ler do stdin passar a mensagem para um pipe anonimo, o filho por sua vez ira ler desse pipe e escrever no stdout

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 512

int main()
{
    //Criação de um pipe anonimo 
    int pd[2];
    char *buf = malloc(BUFSIZE * sizeof(char));

    if(pipe(pd) == -1){//Erro na criação do pipe
        perror("Pipe");
        return 1;
    }
    //Criação de um processo filho 
    pid_t pid = fork(); //Criação de um processo filho 

    switch(pid){
        case -1://Erro na criação do processo filho
            perror("Pid");
            return 1;
        break;
        case 0: ; //Filho - (herdou a tabela de descritores de ficheiros do pai)
            ssize_t n;//n stands for numero de bites lidos
            //O filho nunca ira escrever no pipe anonimo logo iremos fechar esse descritor
            close(pd[1]);
            //Leitura da mensagem do pipe anonimo 
            n = read(pd[0], buf, sizeof(buf));
            //Fecho do descritor de leitura do pipe anonimo 
            close(pd[0]);
            //Escrita no stdout 
            write(1, buf, n);
        break;
        default:    //Pai
            //O pai nunca ira ler do pipe anonimo logo iremos fechar esse descritor
            close(pd[0]);
            //Leitura de string do stdin
            read(0, buf, sizeof(buf));
            //Envio da leitura do stdin pelo pipe anonimo - escrita no pipe
            write(pd[1], buf, sizeof(buf));
            //Fecho do descritor de escrita do pipe anonimo
            close(pd[1]);
        break;
    }
    return 0;
}