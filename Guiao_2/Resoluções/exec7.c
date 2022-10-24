#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

#define ROWS 10
#define COLUMNS 1000

int main()
{
    //Declaração de variaveis 
    int const matrix[ROWS][COLUMNS] = {0};
    int const n = 0;
    int found[ROWS] = {0} , exitStatus, l;
    size_t i, j;

    for(i = 0; i != ROWS; i++){
        if(!fork()){
            for(j = 0; j != COLUMNS; j++){
                if(matrix[i][j] == n)
                    _exit(i);
            }
            _exit(-1);
        }
    }
    for(i = 0; i != ROWS; i++){
        wait(&exitStatus);
        l = WEXITSTATUS(exitStatus);
        if(l != -1)
            found[l]++;
    }
    printf("Encontrado %i na linha: \n", n);
    for(i = 0; i != ROWS; i++){
        if(found[i])
            printf(" %ld", i);
        printf("\n");
    }
}