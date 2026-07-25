#ifndef FILAS_H
#define FILAS_H

#include "grafos.h"
#include <stdlib.h>
#include <stdio.h>

struct no {
    int valor;
    struct no* proximo;
};

typedef struct {
    int tamanho;
    struct no* comeco;
    struct no* fim;
} Fila;

Fila* iniciaFila();

void enfileira(int valor, Fila* fila);

int desenfileira(Fila* fila);

void liberaFila(Fila* f);

#endif