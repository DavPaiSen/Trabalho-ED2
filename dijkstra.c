#include "dijkstra.h"

#define INFINITO INT_MAX

//retorna o numero do vertice nao visitado com a menor distancia para os visitados
int menorDistancia(int* distancia, int* visitado, int v) {
    int minimo = INFINITO;
    int retorno = -1;

    for (int i = 0; i < v; i++) {
        if (!visitado[i] && distancia[i] < minimo) {
            minimo = distancia[i];
            retorno = i;
        }
    }
    return retorno;
}

void imprimeCaminho(int* antecessor, int vertice) {
    if (antecessor[vertice] == -1) {
        printf("%d", vertice);
        return;
    }

    imprimeCaminho(antecessor, antecessor[vertice]);
    printf("-> %d ", vertice);
}

int dijkstra(Grafo* g, int origem, int destino) {
    if (!g) {
        printf("Grafo nulo!\n");
        return -1;
    }
    
    if (origem < 0 || origem >= g->V || destino < 0 || destino >= g->V) {
        printf("Origem ou destinos invalidos!\n");
        return -1;
    }

    int* distancia = malloc(sizeof(int) * g->V);
    int* visitado = calloc(g->V, sizeof(int));
    int* antecessor = malloc(sizeof(int) * g->V);

    for (int i = 0; i < g->V; i++) {
        distancia[i] = INFINITO;
        antecessor[i] = -1;
    }

    distancia[origem] = 0;

    for (int i = 0; i < g->V - 1; i++) {
        int vertice = menorDistancia(distancia, visitado, g->V);

        if (vertice == -1 || distancia[vertice] == INFINITO) {
            break;
        }

        visitado[vertice] = 1;

        if (vertice == destino) {
            break;
        }

        No* percorre = g->lista[vertice];

        while (percorre) {
            int vizinho = percorre->destino;
            int peso = percorre->peso;

            if (!visitado[vizinho] && distancia[vertice] != INFINITO && distancia[vertice] + peso < distancia[vizinho]) {
                distancia[vizinho] = distancia[vertice] + peso;
                antecessor[vizinho] = vertice;
            }
            percorre = percorre->prox;
        }
    }

    int distanciaTotal = distancia[destino];

    if (distanciaTotal == INFINITO) {
        free(distancia);
        free(visitado);
        free(antecessor);
        return -1;
    }

    imprimeCaminho(antecessor, destino);
    printf("\n");
    free(distancia);
    free(visitado);
    free(antecessor);

    
    return distanciaTotal;
}