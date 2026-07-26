#include "topologica.h"

//assumindo aqui que o grafo e aciclico!!!!!!!!!
void ordemTopologica(Grafo* g) { //algoritmo de Kahn
    Fila* fila = iniciaFila();
    int t = 0;
    int* ordem = malloc(sizeof(int) * g->V);
    int* deg = malloc(sizeof(int) * g->V);//deg-

    for (int i = 0; i < g->V; i++) {
        deg[i] = degMenos(i, g);
        if (deg[i] == 0) {
            enfileira(i, fila);
        }
    }

    int vertice;
    while (fila->tamanho > 0) {
        vertice = desenfileira(fila);
        ordem[vertice] = t;
        t++;
        No* percorre = g->lista[vertice];
        while (percorre) {
            deg[percorre->destino]--;
            if (deg[percorre->destino] == 0) {
                enfileira(percorre->destino, fila);
            }
            percorre = percorre->prox;
        }
    }

    for (int i = 0; i < g->V; i++) {
        printf("%d ", ordem[i]);
    }

    printf("\n");

    free(ordem);
    free(deg);
    liberaFila(fila);
}