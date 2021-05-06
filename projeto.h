#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Na estrutura do vértice foi adicionada n_arestas, a qual só é modificada e utilizada no primeiro
vértice da listaAdj[u] de tal forma a facilitar a contagem de opções presentes no vértice u
na função escolher()
*/

// estrutura vértice/nó da lista
typedef struct vertice {
    int n_arestas;
   int identificador;
   struct vertice *proximo;

} Vertice;

// estrutura grafo
typedef struct grafo {
   int arestas;
   int V;
   Vertice **listaAdj;
} Grafo;

// funções do grafo
Grafo* criar_grafo (int tamanho);
void inserir_aresta (Grafo *G, int u, int v); 
void liberar_grafo (Grafo *G); 

// montagem do jogo
void vetor_historia(char **v);
void liberar_historias(char **v);
void build(Grafo *g, char **v); 

// ferramentas de jogabilidade
void escolher(char **v, Grafo* g, int id);
void acesso_vertice(int id, char **v);

// ferramenta de auxílio
void imprime_texto(char *nome_arq);

// jogar
void play(Grafo *g, char **v);