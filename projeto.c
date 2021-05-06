#include "projeto.h"
#define TAM 24
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
            char d = i%10 + 1 + '0';
            char temp[STR] = {'t','e','x','t','/','0','0',d,  c,'.','t','x','t'};
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
    system("cls");
    FILE* texto = fopen(nome_arq, "r");
    printf("\nAbrindo arquivo %s...\n", nome_arq);
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
    inserir_aresta(g, 0, 3);
    inserir_aresta(g, 1, 4);
    inserir_aresta(g, 1, 5);
    inserir_aresta(g, 2, 6);
    inserir_aresta(g, 2, 7);
    inserir_aresta(g, 3, 8);
    inserir_aresta(g, 3, 9);
    inserir_aresta(g, 4, 10);
    inserir_aresta(g, 4, 11);
    inserir_aresta(g, 4, 12);
    inserir_aresta(g, 4, 13);
    inserir_aresta(g, 5, 4);
    inserir_aresta(g, 5, 39);
    inserir_aresta(g, 5, 15);
    inserir_aresta(g, 6, 16);
    inserir_aresta(g, 6, 17);
    inserir_aresta(g, 7, 18);
    inserir_aresta(g, 7, 19);
    inserir_aresta(g, 8, 20);
    inserir_aresta(g, 8, 21);
    inserir_aresta(g, 9, 8);
    inserir_aresta(g, 9, 39);
    inserir_aresta(g, 12, 22);
    inserir_aresta(g, 12, 23);
    inserir_aresta(g, 13, 39);
    inserir_aresta(g, 13, 5);
    inserir_aresta(g, 15, 24);
    inserir_aresta(g, 15, 25);
    inserir_aresta(g, 16, 26);
    inserir_aresta(g, 16, 27);
    inserir_aresta(g, 17, 39);
    inserir_aresta(g, 17, 28);
    inserir_aresta(g, 18, 29);
    inserir_aresta(g, 18, 29);
    inserir_aresta(g, 20, 30);
    inserir_aresta(g, 20, 39);
    inserir_aresta(g, 24, 38);
    inserir_aresta(g, 26, 7);
    inserir_aresta(g, 26, 39);
    inserir_aresta(g, 27, 32);
    inserir_aresta(g, 27, 37);
    inserir_aresta(g, 28, 33);
    inserir_aresta(g, 28, 34);
    inserir_aresta(g, 29, 39);
    inserir_aresta(g, 30, 45);
    inserir_aresta(g, 30, 31);
    inserir_aresta(g, 32, 35);
    inserir_aresta(g, 33, 36);
    inserir_aresta(g, 34, 38);
    inserir_aresta(g, 37, 39);
    inserir_aresta(g, 39, 42);
    inserir_aresta(g, 39, 43);
    inserir_aresta(g, 41, 14);
    inserir_aresta(g, 41, 14);
    inserir_aresta(g, 41, 44);
    inserir_aresta(g, 45, 38);
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
