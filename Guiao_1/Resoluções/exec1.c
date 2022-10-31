#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUF_SIZE 1024

int main(int argc, char const *argv[])
{
    //Declaração e inicialização de dados 
    int origem, destino;
    char buf[BUF_SIZE];
    ssize_t tamanhoLido;
    if(argc < 2){
        perror("Numero de argumentos insuficientes\n");
        return 1;
    }

    origem = open(argv[1], O_RDONLY);
    if(origem == -1){
        perror( "Não existe no diretorio\n");
        return 1;
    }

    destino = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);

    while(tamanhoLido == read(origem, buf, BUF_SIZE));
        write(destino, buf, tamanhoLido);

    close(origem);
    close(destino);
    return 0;
}