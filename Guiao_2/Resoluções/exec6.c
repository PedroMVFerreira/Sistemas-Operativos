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
    int found = 0, exitStatus;
    size_t i, j;

    for(i = 0; i != ROWS; i++){
        if(!fork()){
            for(j = 0; j != COLUMNS; j++){
                if(matrix[i][j] == n){
                    printf("Linha:\t %ld\n", i);
                    found++;
                }
            }
            _exit(found);
        }
    }
    for(size_t i = 0; i < ROWS; ++i) {
        wait(&exitStatus);
        found += WEXITSTATUS(exitStatus);
    }
    printf("Um total de %i ocorrencias foram encontradas na matriz\n", found);
    return 0;
}