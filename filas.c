#include "filas.h"

Fila* iniciaFila() {
    Fila* nova = malloc(sizeof(Fila));
    nova->comeco = NULL;
    nova->fim = NULL;
    nova->tamanho = 0;
    return nova;
}

void enfileira(int valor, Fila* fila) {
    if (!fila) {
        printf("Fila nao alocada!\n");
        return;
    }

    struct no* novo = malloc(sizeof(struct no));
    novo->proximo = NULL;
    novo->valor = valor;
    
    if (fila->tamanho == 0) {
        fila->comeco = novo;
        fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
    fila->tamanho++;
}

int desenfileira(Fila* fila) {
    if (!fila || fila->tamanho == 0) {
        printf("Nao foi possivel desenfileirar o valor!\n");
        return -1;
    }

    struct no* desenfileirar = fila->comeco;
    int retorno = desenfileirar->valor;
    fila->comeco = desenfileirar->proximo;

    if (fila->tamanho == 0) {
        fila->fim = NULL;
    }

    fila->tamanho--;
    free(desenfileirar);
    return retorno;
}

void liberaFila(Fila* f) {
    if (!f) {
        return;
    }

    struct no* percorre = f->comeco;
    struct no* prox;
    while (percorre) {
        prox = percorre->proximo;
        free(percorre);
        percorre = prox;
    }

    free(f);
}