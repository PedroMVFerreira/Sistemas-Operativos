#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

int main(int argc, char const *argv[])
{
    //Declaração e inicialização de dados
    char *buf = malloc(BUF_SIZE * sizeof(char));
    ssize_t tamanhoLido;

    tamanhoLido = read(STDIN_FILENO, buf, BUF_SIZE);
    write(STDOUT_FILENO, buf, tamanhoLido);
    
    free(buf);
    return 0;
}