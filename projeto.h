#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vertice {
    int n_arestas;
   int identificador;
   struct vertice *proximo;

} Vertice;

typedef struct grafo {
   int arestas;
   int V;
   Vertice **listaAdj;
} Grafo;

// funções do grafo
Grafo* criar_grafo (int tamanho); // CHECK andrea
void inserir_aresta (Grafo *G, int u, int v); // CHECK andrea
void liberar_grafo (Grafo *G); // CHECK andrea

// montando o jogo
void vetor_historia(char **v);
void liberar_historias(char **v);
void build(Grafo *g, char **v); // sendo implementado

// ferramentas de jogabilidade
void escolher(char **v, Grafo* g, int id);
void acesso_vertice(int id, char **v);

// ferramenta de auxílio
void imprime_texto(char *nome_arq); // CHECK andrea

// jogar
void play(Grafo *g, char **v);
