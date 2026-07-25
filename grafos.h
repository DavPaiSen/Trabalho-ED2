#ifndef GRAFOS_H
#define GRAFOS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int destino;
    int peso;
    struct No *prox;
} No;

typedef struct {
    int V; // Número de vértices
    int A; // Número de arestas
    No **lista; // Lista de adjacência
} Grafo;

Grafo criaGrafo(int vertices, int arestas);

void desalocaGrafo(Grafo* g);

void adicionaAresta(Grafo* g, int origem, int destino, int peso);

Grafo* grafoDoArquivo(char* nomeArquivo);

void mostrarGrafo(Grafo* g);

int degMais(Grafo* g, int n);

#endif