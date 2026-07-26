#include "prim.h"

typedef struct {
    int origem;
    int destino;
    int peso;
} Aresta;

//retorna o vertice que deve ser selecionado para o alg de Prim, verticesInclusos sao os vertices que ja estao na arvore
Aresta menorCusto(Grafo* g, int* verticesInclusos) {
    Aresta retorno;
    retorno.destino = -1;
    retorno.origem = -1;
    retorno.peso = INT_MAX;

    for (int i = 0; i < g->V; i++) {
        if (!verticesInclusos[i]) {
            continue;
        }

        No* percorre = g->lista[i];
        while (percorre) {
            if (!verticesInclusos[percorre->destino] && percorre->peso < retorno.peso) {
                retorno.destino = percorre->destino;
                retorno.peso = percorre->peso;
                retorno.origem = i;
            }
            percorre = percorre->prox;
        }
    }
    return retorno;
}

//retorna o peso total da arvore 
int prim(Grafo* g) {
    if (!g) {
        printf("Grafo nulo!\n");
        return -1;
    }

    int* verticesInclusos = calloc(g->V, sizeof(int));
    int tamanhoArvore = 1;
    int pesoArvore = 0;
    verticesInclusos[0] = 1;
    Aresta* arvore = malloc(sizeof(Aresta) * (g->V - 1));

    while (tamanhoArvore != g->V) {
        arvore[tamanhoArvore-1] = menorCusto(g, verticesInclusos);
        if (arvore[tamanhoArvore-1].destino == -1) {
            printf("Grafo desconexo!\n");
            free(verticesInclusos);
            free(arvore);
            return -1;
        }
        pesoArvore += arvore[tamanhoArvore-1].peso;
        verticesInclusos[arvore[tamanhoArvore-1].destino] = 1;
        tamanhoArvore++;
    }

    for (int i = 0; i < tamanhoArvore - 1; i++) {//printa os vertices escolhidos
        printf("Origem: %d\tDestino: %d\tPeso: %d\n", arvore[i].origem, arvore[i].destino, arvore[i].peso);
    }

    free(verticesInclusos);
    free(arvore);
    return pesoArvore;
}