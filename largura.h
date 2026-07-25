#ifndef LARGURA_H
#define LARGURA_H

#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

struct no {
    int valor;
    struct no* proximo;
};

typedef struct {
    int tamanho;
    struct no* comeco;
    struct no* fim;
} Fila;

void buscaEmLargura(Grafo* g);

void distanciaDoVertice(Grafo* g, int origem);

#endif