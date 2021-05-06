#include "projeto.h"
#define TAM 4
#define STR 14
#include <time.h>

/*Inicializa o grafo com tamanho constante TAM, correspondente a quantidade 
de pontos na história*/
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

/*Coloca o vértice "v" na lista de adjacências do vértice "u"*/
void inserir_aresta (Grafo *G, int u, int v) {

   Vertice *temp, *ultimo = NULL;

    for (temp = G->listaAdj[u]; temp != NULL; temp = temp->proximo) {
        if (temp->identificador == v) {
            return;
        }
        ultimo = temp;
    }

    Vertice *novo = (Vertice *)malloc(sizeof(Vertice));
    novo->identificador = v;
    novo->proximo = NULL;
    if (ultimo != NULL) {
       ultimo->proximo = novo;
       G->listaAdj[u]->n_arestas++;
    }
    else {
        G->listaAdj[u] = novo;
        G->listaAdj[u]->n_arestas = 1;
    }
    G->arestas++;
}

/*Cria o vetor com os nomes dos arquivos de texto*/
void vetor_historia(char **v){

    int i;
    for(int j =0; j < TAM-1; j++){
        v[j]=(char*)malloc(STR*sizeof(char));
    }

    for(i = 0; i < TAM-1; i++){
        if(i < 10){
            char c = i + 1 + '0';
            char temp[STR] = {'t','e','x','t','/','0','0','0', c,'.','t','x','t'};
            strcpy(v[i], temp);
        }
        if(i >= 10 && i < 99){
            char c = i + 1 + '0';
            char temp[STR] = {'t','e','x','t','/','0','0', c,'.','t','x','t'};
            strcpy(v[i], temp);
        }
    }
}

/*
A funcao escolher é o mecanismo resposável por receber a da escolha feita pelo usuário
e direciona-lo para o próximo vértice da história
*/
void escolher(char **v, Grafo* g, int id){
    if(g->listaAdj[id]==NULL){
        printf("FIM DA HISTÓRIA");
        return;
    }

    int ch;

    printf("\nQual a sua escolha?\n");

    scanf("%d", &ch);
    while(1){
        if(ch > 0 && ch <= g->listaAdj[id]->n_arestas){
            ch-=1;
            Vertice* temp = g->listaAdj[id];
            sleep(2);
            int i = 0;
            while (i < ch) {
                temp = temp->proximo;
                i++;
            }

            acesso_vertice(temp->identificador, v);
            escolher(v, g, temp->identificador);
            break;
        }
        else {

            printf("ERROR[INVALID INPUT]: PLEASE CHOOSE AGAIN OR ENTER -1 TO LEAVE\n");
            while ((ch = getchar()) != EOF && ch != '\n');
            scanf("%d", &ch);
            if (ch == -1)
                break;
        }

    }

}

/*
A função acesso_vertice é auxiliar, só utilizada para imprimir o texto correspondente 
ao vértice
*/
void acesso_vertice(int id, char **v){
    imprime_texto(v[id]);
}

/*
A funcao imprime_texto tem como parâmetro uma string: 
- o nome do arquivo a ser impresso no console
A partir disso, ele imprime caráctere por caráctere e caso for encontrado um "%" ele esperará
2 segundos para continuar a imprimir (para que todo o texto não seja mostrado de uma única vez)
*/
void imprime_texto(char *nome_arq){

    char c;
    system("clear");
    FILE* texto = fopen(nome_arq, "r");
    if(texto){
        while ((c = getc(texto)) != EOF){
            if(c == '%'){
                printf("\n");
                sleep(2);
                continue;
            }
            putchar(c);
        }
        fclose(texto);
    } else {
        printf("ERROR: %s NOT FOUND\n", nome_arq);

    }

}

// A funcao liberar_grafo libera a memória alocada do grafo
void liberar_grafo (Grafo *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      if (G->listaAdj[v] != NULL) {
         free(G->listaAdj[v]);
      }
   }
   free(G->listaAdj);
   free(G);
}

/* 
A funcao build é encarregada de montar o jogo. Nela:
- todas as arestas são inseridas
- é chamado vetor_historia, que coloca o nome dos arquivos txt no vetor de strings v
*/
void build(Grafo* g, char **v){

    inserir_aresta(g, 0, 1);
    inserir_aresta(g, 0, 2);

    vetor_historia(v);

}


/*
A função play é responsável por dar início ao jogo. Ela imprime o trecho inicial do jogo,
e manda à função escolher o primeiro vértice.
*/

void play(Grafo* g, char **v){
    char iniciar;

    imprime_texto("text/init.txt");
    iniciar=fgetc(stdin);

    while(iniciar!=0x0A){
        iniciar=fgetc(stdin);
    }
    imprime_texto(v[0]);
    escolher(v, g, 0);
}

int main(){

    Grafo* g = criar_grafo(TAM);
    char* vetor_nomes[TAM];

    build(g, vetor_nomes);
    play(g, vetor_nomes);

    liberar_grafo(g);

    return 0;
}
