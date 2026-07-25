#include "largura.h"
#include "grafos.h"

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

void ajudaLargura(Grafo* g, int atual, int* visitado) {
    Fila* fila = iniciaFila();
    visitado[atual] = 1;
    enfileira(atual, fila);

    while(fila->tamanho > 0) {
        int atual = desenfileira(fila);
        printf("%d ", atual);

        No* percorre = g->lista[atual];
        while (percorre) {
            int vizinho = percorre->destino;

            if(!visitado[vizinho]) {
                visitado[vizinho] = 1;
                enfileira(vizinho, fila);
            }
            percorre = percorre->prox;
        }

    }

    liberaFila(fila);
}

void buscaEmLargura(Grafo* g) {
    if(!g) {
        printf("Grafo nao alocado!\n");
        return;
    }

    int* visitado = calloc(g->V, sizeof(int));

    for (int i = 0; i < g->V; i++) {
        if (!visitado[i]) {
            ajudaLargura(g, i, visitado);
        }
    }

    free(visitado);

    printf("\n");
}

void distanciaDoVertice(Grafo* g, int origem) {//so mudei o algoritmo da busca em largura acima
    if (!g) {
        printf("Grafo nao alocado!\n");
        return;
    }

    int* distancia = malloc(sizeof(int) * g->V);
    for (int i = 0; i < g->V; i++) {
        distancia[i] = -1;//distancia negativa simbolizando que nao da pra chegar nesse vertice a partir do vertice de origem
    }

    Fila* fila = iniciaFila();

    distancia[origem] = 0;
    enfileira(origem, fila);

    while (fila->tamanho > 0) {
        int atual = desenfileira(fila);

        No* percorre = g->lista[atual];

        while (percorre) {
            int vizinho = percorre->destino;

            if (distancia[vizinho] == -1) {
                distancia[vizinho] = distancia[atual] + 1;//distancia do que veio antes mais 1
                enfileira(vizinho, fila);
            }

            percorre = percorre->prox;
        }
    }
    liberaFila(fila);

    for (int i = 0; i < g->V; i++) {
        printf("Vertice: %d distancia: ", i);
        if (distancia[i] == -1) {
            printf("inalcancavel\n");
        } else {
            printf("%d\n", distancia[i]);
        }
    }
    
    free(distancia);
}