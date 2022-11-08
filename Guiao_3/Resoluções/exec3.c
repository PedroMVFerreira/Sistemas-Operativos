#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>	/* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <stdio.h>
#include <stdlib.h>

#define MAXBUFFER 1024

int main(int argc, char *argv[]){
	int fd[2];
	pipe(fd);
	char buffer[MAXBUFFER];
	int size, status, i=0;
	pid_t pid;

	if(fork() == 0){//Processo filho
        close(fd[0]);//Fecho do descritor de leitura no pipe anonimo -> processo pai
		write(1, "Son said to his father: ", sizeof("Son said to his father: "));
		
        //sleep(5);//Rotina de espera (para verificação do bloqueio da leitura por parte do filho)
		write(fd[1], "12", sizeof("12"));//Escrita no descritor de escitra do pipe anonimo -> possibilitando a leitura ao filho
		close(fd[1]);//Fecho do descritor de escrita no pipe anonimo -> processo pai
	} 
    else {//Processo filho
		close(fd[1]);//Fecho do descritor de escrita no pipe anonimo -> processo filho
		
        //Leitura do descritor de leitura do pipe anonimo -> receção da mensagem escrita pelo pai
		while(read(fd[0], buffer+i, 1))
			i+=1;
		
		buffer[i] = '\0';
        close(fd[0]);//Fecho do descritor de leitura no pipe anonimo -> processo filho
		write(STDOUT_FILENO, buffer, i);//Escrita no stdout do counteudo lido no pipe
	}
    return 0;//Encerramento do programa com sucesso
}