#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ESTRUTURA DO GRAFO*/

typedef struct vertice {
   char* nome_arq;
   int identificador; // a posicao na lista de adj
   struct vertice *proximo;

} Vertice;

typedef struct grafo {
   int arestas;
   int V;
   Vertice **listaAdj; // Lista de adjacências: lista de ponteiros de vértices
} Grafo;

Grafo* criar_grafo (int tamanho);
void inserir_aresta (Grafo *G, int u, int v, char* vect[]);
char* get_texto (int linha, FILE* arq); // inserir FILE como parâmetro
int conta_linhas(FILE* file);
int get_dado(Grafo *g, int linha);
void liberar_grafo (Grafo *G); // ultima coisa a ser implementada
void imprime_texto(char *nome_arq);
void build();
void escolher(char **v, Grafo* g, int id);
void acesso_vertice(int id, char **v);
void vetor_historia(char **v);
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


