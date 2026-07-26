#include "grafos.h"
#include "profundidade.h"
#include <stdio.h>

void ajudaRecursiva(Grafo* g, int* visitado, int atual, int printar) {
    visitado[atual] = 1;
    if (printar) {
        printf("%d ", atual);
    }

    No* percorre = g->lista[atual];

    while (percorre) {
        int vizinho = percorre->destino;

        if (!visitado[vizinho]) {
            ajudaRecursiva(g, visitado, vizinho, printar);
        }
        percorre = percorre->prox;
    }
}

int buscaProfundidadeRecursiva(Grafo* g, int printar) { //retorna o numero de componentes conexas
    if (!g) {
        printf("Grafo nulo!!!!!\n");
        return 0;
    }

    int* visitado = calloc(g->V, sizeof(int));
    int componentesConexas = 0;

    for (int i = 0; i < g->V; i++) {
        if (!visitado[i]) {
            ajudaRecursiva(g, visitado, i, printar);
            componentesConexas++; //so vai passar aqui mais de uma vez se a primeira chamada da funcao auxiliar nao marcar todo mundo como visitado
        }
    }

    
    if (printar) {
        printf("\n");
    }
    free(visitado);
    return(componentesConexas);
}

typedef struct {
    int* elementos;
    int topo;
    int capacidade;
} Pilha;

Pilha* criaPilha(int capacidade) {
    Pilha* nova = malloc(sizeof(Pilha));
    nova->elementos = malloc(sizeof(int) * capacidade);
    nova->capacidade = capacidade;
    nova->topo = -1;
    return nova;
}

void push(Pilha* p, int valor) {
    p->elementos[++(p->topo)] = valor;
}

int pop(Pilha* p) {
    return p->elementos[p->topo--];
}

void liberaPilha(Pilha* p) {
    free(p->elementos);
    free(p);
}

int buscaProfundidadeIteratira(Grafo* g) {
    if (!g) {
        printf("Grafo nulo!!\n");
        return -1;
    }

    int* visitado = calloc(g->V, sizeof(int));
    Pilha* p = criaPilha(g->V);
    int componentesConexas = 0;

    for (int i = 0; i < g->V; i++) {
        if (!visitado[i]) {
            componentesConexas++;

            push(p, i);

            while(p->topo != -1) {//enquanto tiver alguma coisa na pilha
                int visitar = pop(p);

                if (!visitado[visitar]) {
                    visitado[visitar] = 1;
                    printf("%d ", visitar);

                    No* atual = g->lista[visitar];
                    while (atual) {
                        int vizinho = atual->destino;
                        if (!visitado[vizinho]) {
                            push(p, vizinho);
                        }
                        atual = atual->prox;
                        //vai ver se os vizinhos do i ja foram visitados, se nao, coloca eles na pilha para serem visitados
                    }
                }
            }
        }
    }
    printf("\n");
    free(visitado);
    liberaPilha(p);
}