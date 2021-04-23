#include <stdio.h>
#include <stdlib.h>
#include <time.h> //para usar o sleep
#define MAX_STRING 8


void imprime_texto(char *nome_arq){

    char c;
    FILE* texto = fopen(nome_arq, "r");
    if(texto){
        while ((c = getc(texto)) != EOF){
            if(c == '\\'){ // o "\" é usado como identificador de parágrafo
                printf("\n");
                sleep(2);
                continue;
            }
            putchar(c); //printa letra por letra
        }
        fclose(texto);
    }

}


int main(void)
{

    imprime_texto("text/0001.txt");

    return 0;
}
