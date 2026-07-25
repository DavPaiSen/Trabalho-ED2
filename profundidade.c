#include "grafos.h"
#include "profundidade.h"
#include <stdio.h>

void ajudaRecursiva(Grafo* g, int* visitado, int atual) {
    visitado[atual] = 1;
    printf("%d ", atual);

    No* percorre = g->lista[atual];

    while (percorre) {
        int vizinho = percorre->destino;

        if (!visitado[vizinho]) {
            ajudaRecursiva(g, visitado, vizinho);
        }
        percorre = percorre->prox;
    }
}

int buscaProfundidadeRecursiva(Grafo* g) { //retorna o numero de componentes conexas
    if (!g) {
        printf("Grafo nulo!!!!!\n");
        return 0;
    }

    int* visitado = calloc(g->V, sizeof(int));
    int componentesConexas = 0;

    for (int i = 0; i < g->V; i++) {
        if (!visitado[i]) {
            ajudaRecursiva(g, visitado, i);
            componentesConexas++; //so vai passar aqui mais de uma vez se a primeira chamada da funcao auxiliar nao marcar todo mundo como visitado
        }
    }

    return(componentesConexas);
    printf("\n");
    free(visitado);
}



int buscaProfundidadeIteratira(Grafo* g) {

}