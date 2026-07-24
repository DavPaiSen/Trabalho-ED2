#include <stdlib.h>
#include "grafos.h"
#include <stdio.h>
#define TAMANHO_BUFFER 100

Grafo criaGrafo(int vertices, int arestas) {
    Grafo novo;
    novo.V = vertices;
    novo.A = arestas;

    novo.lista = malloc(sizeof(No*)* vertices);
    for (int i = 0; i < vertices; i++) {
        novo.lista[i] = NULL;
    }

    return novo;
}

void adicionaAresta(Grafo* g, int origem, int destino, int peso) {
    No* aresta = malloc(sizeof(No));
    aresta->destino = destino;
    aresta->peso = peso;

    //insere no inicio da lista de adjacencia

    aresta->prox = g->lista[origem];
    g->lista[origem] = aresta;
}

Grafo* grafoDoArquivo(char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo!\n");
        return NULL;
    }

    char buffer[TAMANHO_BUFFER]; //le uma linha do tamanho 100 por vez do arquivo

    int vertice, aresta;

    if (!fgets(buffer, TAMANHO_BUFFER, arquivo)) {
        printf("Erro ao ler o arquivo!\n");
        return NULL;
    }

    if (sscanf(buffer, "%d %d", &vertice, &aresta) != 2) {
        printf("Primeira linha no formato errado!\n");
        fclose(arquivo);
        return NULL;
    }

    Grafo* novo = malloc(sizeof(Grafo));
    *novo = criaGrafo(vertice, aresta);

    int origem, destino, peso;
    while (fgets(buffer, TAMANHO_BUFFER, arquivo)) { //enquanto existir arquivo para ler
        if (sscanf(buffer, "%d %d %d", &origem, &destino, &peso) != 3) {
            printf("Alguma linha esta no formato errado!\n");
            fclose(arquivo);
            return NULL;
        }
        adicionaAresta(novo, origem, destino, peso);
    }
    
    fclose(arquivo);
    return novo;
}