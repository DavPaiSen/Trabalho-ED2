#include "estatisticas.h"

int conexo(Grafo* g) {
    if (buscaProfundidadeRecursiva(g, 0) == 1) {
        return 1;
    }
    return 0;
}

void grauDosVertices(Grafo* g) {
    for (int i = 0; i < g->V; i++) {
        printf("Vertice: %d -> deg+ = %d e deg- = %d\n", i, degMais(i, g), degMenos(i, g));
    }
}

int temVolta(Grafo* g, int origem, int destino) {
    No* atual = g->lista[destino];

    while (atual) {
        if (atual->destino == origem) {
            return 1;
        }
        atual = atual->prox;
    }
    return 0;
}

int direcionado(Grafo* g) {//direcionado se para toda aresta x->y tem uma aresta y->x
    No* atual = NULL;
    for (int i = 0; i < g->V; i++) {
        atual = g->lista[i];
        while (atual) {
            if (!temVolta(g, i, atual->destino)) {
                return 0;
            }
            atual = atual->prox;
        }
    }
    return 1;
}

static int ajudaRecursiva(Grafo* g, int x, int* visitados, int* recursao) {
    if (recursao[x]) {
        return 1;
    }

    if (visitados[x]) {
        return 0;
    }

    visitados[x] = 1;
    recursao[x] = 1;

    No* atual = g->lista[x];
    while (atual) {
        if (ajudaRecursiva(g, atual->destino, visitados, recursao)) {
            return 1;
        }
        atual = atual->prox;
    }

    recursao[x] = 0;
    return 0;
}

//adaptado de https://www.geeksforgeeks.org/dsa/detect-cycle-in-a-graph/
int temCiclo(Grafo* g) {
    int* visitados = calloc(g->V, sizeof(int));
    int* recursao = calloc(g->V, sizeof(int));

    for (int i = 0; i < g->V; i++) {
        if (!visitados[i] && ajudaRecursiva(g, i, visitados, recursao)) {
            return 1;
        }
    }
    return 0;
}