/*Exercicio: O processo pai devera ler uma frase do stdin que sera passada atrasves de pipes anonimo a diferentes processos filhos que terão a função de 
saber se a frase cumpre determinados requisitos e irão passar o resultado dessas verificações de volta ao pai
Filho 1 - numero de caracteres (maior do que 5)
Filho 2 - numero de digitos (maior do que 2)
Filho 3 - numero de caracteres de pontuação (maior do que 2)*/

#include <unistd.h>
#include <ctype.h>
#include <stdio.h>

int main()
{
    //Declaração e inicialização de variaveis
    char linha[512], res = 0, c = 0, aux;
    int n, i, j, k, ok = 0; 
    int pd[4][2];

    //Criação de 4 pipes anonimos (3 para o envio da mensagem do pai para os diferentes filhos e 1 para envio de resultaods)
    for(i = 0; i != 4; i++)
        pipe(pd[i]);
    //Criação de 3 processos filhos
    for(i = 0; i != 3; i++){
        if(fork() == 0){//Criação do filho de indice i
            for(k = 0; k != 3; k++){//Fecho dos descritores que o filho em questão não necessita
                close(pd[k][1]);//O filho nunca ira escrever nos pipes dos quais recebe informação do seu pai
                if(k < i)
                    close(pd[k][0]);//O filho i apenas ira ler do seu pipe respetivo podemos assim fechar os outros pipes 
            }
            close(pd[3][0]);//Os filhos nunca irão escrever no pipe usado para enviar o resultado das comunicações de volta ao pai 
            while((n = read(pd[i][0], linha, sizeof(linha))) > 0){//Os filhos lerão o conteudo dos diferentes pipes passados pelo pai
                switch(i){
                    case 0://Filho 1
                        res = (n > 5);
                    break;
                    case 1://Filho 2
                        for(j = 0; j != n; j++){
                            if(isdigit(linha[j]))//Sempre que o caracter seja um digito o contador aumentara
                                c++;
                        }
                        res = c > 2;
                    break;
                    case 2://Filho 3
                        for(j = 0; j != n; j++){
                            if(ispunct(linha[j]))//Sempre que o caracter seja um caracter de pontuação o contador aumentara
                                c++;
                        }
                        res = c > 2;
                    break;
                }//Fim do switch case diferentes filhos diferentes tratamentos
            close(pd[i][0]);//Fecho do descritor de leitura do pipe nos filhos
            }//Fim da leitura dos pipes
        }///Fim de filhos
    }//Fim da criação de 3 processos filhos
    for(i = 0; i != 3; i++)
        close(pd[i][0]);//Fecho do descritor de leitura nos pipes que o pai apenas usa para passar informação aos filhos
    while(!ok && (n = read(0, linha, sizeof(linha))) > 0){//Iremos ler uma nova linha enquanto estivermos a escrever a mesma ou a linha lida não for valida 
        ok = 1;
        for(i = 0; i != 3; i++)//Escrita da linha lida do stdin nos diferentes pipes para ser tratada pelos 3 filhos
            write(pd[i][1], linha, n); 
        for(i = 0; i != 3; i++){//Leitura do resultado das verificações enviados pelos filhos atraves do pipe
            read(pd[3][0], &aux, sizeof(aux));
            ok = ok && aux;
        }
        if(ok == 0)
            write(2, "Linha invalida\n", 15);//Escrita de uma mensagem de erro no stderr
        else
            write(1, "Linha valida\n", 13);//Escrita de uma mensagem de sucesso no stdout
    }//Fim do ciclo de verificação e leitura de nova linha
    close(pd[3][0]);//Fecho do descritor de leitura do pipe 3 (envio de resultados dos filhos para pai) por parte do pai
    for(i = 0; i != 3; i++)
        close(pd[i][1]);//Fecho do descritor de escrita nos 3 primeiros pipes (envio da frase do pai para os filhos) por parte do pai
    //Programa terminou com sucesso
    return 0;
}