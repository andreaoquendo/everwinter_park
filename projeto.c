#include "projeto.h"

Grafo* criar_grafo (int tamanho) {
   int v;
   Grafo *G = (Grafo *)malloc(sizeof(Grafo));
   G->E = 0;
   G->V = tamanho;
   G->listaAdj = (Vertice **)malloc(tamanho * sizeof(Vertice *)); // aqui ela crialista uma de lista de vértice...?
   for (v = 0; v < G->V; v++) {
      G->listaAdj[v] = NULL;
   }
   return G;
}

char* get_texto (int linha, FILE* arq){
    /*obtem a string da linha*/
}

int conta_linhas(FILE* file){
    // conta linhas
}

int get_dado(Grafo *g, int linha) {
    //return g->listaAdj[linha]->dado;
}


void inserir_aresta (Grafo *G, int u, int v) { // u é a posição na lista pelo que eu entendi, v é o identoficadoe
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
   novo->dado = get_texto(v+1);
   novo->linha = v;
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
   G->E++;
}

int main(){

    char iniciar;
    // tela de início  que talvez fique melhor no run();

    imprime_texto("text/init.txt");

    iniciar=fgetc(stdin);
    if(iniciar==0x0A){
        printf("\n vamos iniciar entao");
    }
    return 0;




void imprime_texto(char *nome_arq){

    char c;
    FILE* texto = fopen(nome_arq, "r");
    if(texto){
        while ((c = getc(texto)) != EOF){
            if(c == '%'){ // o "\" é usado como identificador de parágrafo
                printf("\n");
                sleep(2);
                continue;
            }
            putchar(c); //printa letra por letra
        }
        fclose(texto);
    } else {
        printf("ERROR: %s NOT FOUND\n", nome_arq);

    }

}
