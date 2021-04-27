#include "projeto.h"
#define TAM 2
#define STR 14
#include <time.h>

Grafo* criar_grafo (int tamanho) {
   int v;
   Grafo *G = (Grafo *)malloc(sizeof(Grafo));
   G->arestas = 0;
   G->V = tamanho;
   G->listaAdj = (Vertice **)malloc(tamanho * sizeof(Vertice *));
   for (v = 0; v < G->V; v++) {
      G->listaAdj[v] = NULL;
   }
   return G;
}

void inserir_aresta (Grafo *G, int u, int v, char** vect) {
   Vertice *temp, *ultimo = NULL;

   /* Verificando se o vértice v já existe na lista de adjacência de u: */
    for (temp = G->listaAdj[u]; temp != NULL; temp = temp->proximo) {
        if (temp->identificador == v) {
            return;
        }
        ultimo = temp;
    }

   /* Inserindo a aresta (u,v): */
    Vertice *novo = (Vertice *)malloc(sizeof(Vertice));
    novo->nome_arq = vect[v];
    novo->identificador = v;
    novo->proximo = NULL;
    if (ultimo != NULL) {
      /* Inserção na última posição da lista: */
       ultimo->proximo = novo;
    }
    else {
      /* Nova cabeça da lista: */
        G->listaAdj[u] = novo;
    }
   /* Incrementando o número de arestas: */
    G->arestas++;
}

void vetor_historia(char **v){

    v[0] = (char*)malloc(STR*sizeof(char));
    strcpy(v[0],"text/0001.txt");
    v[1] = (char*)malloc(STR*sizeof(char));
    strcpy(v[1], "text/0002.txt");

    // 0 = 48, 9 = 57
    /*int i;

    for i from 0 to tam v[i] = '0000.txt';

    i/10<1

    for(i = 0; i < TAM; i++){
        if(i < 10)
            v[i] = '000'i'.txt'; // v[3] = ('0'*(i%10));
        if(i >= 10 && i < 99)
            v[i] = '00'i'.txt';
    }*/
}

void escolher(char **v, Grafo* g, int id){
    printf("\nENTREI NA ESCOLHA %d\n", id);

    if (g->listaAdj[id] != NULL){
        acesso_vertice(id, v);
        if(!g->listaAdj[id]->proximo){
            printf("VOCÊ MORREU\n");
            return;
        }
        Vertice *temp;
        Vertice **listaTemp = (Vertice **)malloc(sizeof(Vertice));

        int a = 0, i;

        for(i = 0, temp = g->listaAdj[id]  ; temp != NULL ; temp = temp->proximo, i++){
            listaTemp[i] = temp;
            a++;

        }
        int ch;
        while(scanf("%d", &ch)){
            if(ch > 0 && ch <= a){
                switch (ch){
                    case 1:
                        escolher(v, g, listaTemp[0]->identificador);
                        break;
                    case 2:
                        escolher(v, g, listaTemp[1]->identificador);
                        break;
                    case 3:
                        escolher(v, g, listaTemp[2]->identificador);
                        break;
                    case 4:
                        escolher(v, g, listaTemp[3]->identificador);
                        break;
                    default:
                        break;
                }
                break;
            }
            else {
                printf("ERROR[INVALID INPUT]: PLEASE CHOOSE AGAIN\n");
            }
        }
    }

}

void acesso_vertice(int id, char **v){
    imprime_texto(v[id]);
}

void imprime_texto(char *nome_arq){

    char c;
    FILE* texto = fopen(nome_arq, "r");
    if(texto){
        while ((c = getc(texto)) != EOF){
            if(c == '%'){
                printf("\n");
                //sleep(2);
                continue;
            }
            putchar(c); //printa letra por letra
        }
        fclose(texto);
    } else {
        printf("ERROR: %s NOT FOUND\n", nome_arq);

    }

}

int main(){

    char* vetor_nomes[TAM];
    vetor_historia(vetor_nomes);

    Grafo* g = criar_grafo(TAM);
    inserir_aresta(g, 0, 0, vetor_nomes);
    inserir_aresta(g, 0, 1, vetor_nomes);
    inserir_aresta(g, 1, 1, vetor_nomes);

    escolher(vetor_nomes, g, 0);



/*
    char iniciar;

    char* nomes[TAM];

    imprime_texto("text/init.txt");

    iniciar=fgetc(stdin);
    if(iniciar==0x0A){
        printf("\n vamos iniciar entao");
    }
    return 0;
*/
}
