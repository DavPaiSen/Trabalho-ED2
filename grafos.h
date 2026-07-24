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