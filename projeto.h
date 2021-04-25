#include <stdio.h>
#include <stdlib.h>

/* ESTRUTURA DO GRAFO*/

typedef struct vertice {
   char* dado; //tipo file ou sei la string
   int linha; // numero da linha no arquivo de texto, identificador
   struct vertice *proximo; // próximo nó da lista encadeada
    //peso

} Vertice;

typedef struct grafo {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   Vertice **listaAdj; /* Lista de adjacências: lista de ponteiros de vértices */
} Grafo;

/* FUNÇÕES DO PROJETO */
char* get_texto (int linha, FILE* arq); // inserir FILE como parâmetro
int conta_linhas(FILE* file);
int get_dado(Grafo *g, int linha);
void inserir_aresta (Grafo *G, int u, int v); //mudar ela
void liberar_grafo (Grafo *G); // ultima coisa a ser implementada
void imprime_texto(char *nome_arq);
void build();
/*
    | O que irá conter o build? |
        -Criar grafo
        -Pegar o file
        -Inserir arestas
*/

void play();
/*

    | O que irá conter o play? |
        - primeiro acesso
        while(nao finalizado)
        - funcao para escolhas
            ->repercussao - switch case com repercussao para cada aresta
        - identificador de final: "tmp = null"

*/

/*

    INFO:
    - cada vértice irá apontar para x vértices tal que x pertence a N entre [2,4];
    - opções fucam na mesma linha que a história/pergunta/problema
    IDEIAS:
    - colocar pesos, para decidir final - DESCOBRIR ONDE COLOCAR OS PESOS
    PERGUNTAS E FUNÇÕES:
    - como fazer o C ler e printar o arquivo de texto.
    - função
*/


