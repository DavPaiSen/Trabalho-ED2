#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"
#include "profundidade.h"

int main() {
    Grafo* g = NULL;
    int escolha = 0;
    int arquivo;

    while (escolha != 9) {
        printf("=== SISTEMA DE GRAFOS ===\n1. Carregar grafo de arquivo\n2. Mostrar grafo (lista de adjacência)\n3. Busca em Profundidade (DFS)\n4. Busca em Largura (BFS)\n5. Ordenação Topológica\n6. Árvore Geradora Mínima (Prim)\n7. Menor Caminho (Dijkstra)\n8. Estatísticas do grafo\n9. Sair\n");
        scanf("%d", &escolha);

        switch (escolha) {
        case 1://carregar de arquivo
            printf("Escolha o arquivo para carregar o grafo (1-4): ");
            scanf("%d", &arquivo);
            
            switch (arquivo) {
            case 1:
                g = grafoDoArquivo("grafo1.txt");
                break;

            case 2:
                g = grafoDoArquivo("grafo2.txt");
                break;

            case 3:
                g = grafoDoArquivo("grafo3.txt");
                break;
            
            case 4:
                g = grafoDoArquivo("grafo4.txt");
                break;
            
            default:
                printf("Entrada invalida!\n");
                break;
            }
            break;

        case 2://mostrar grafo
            mostrarGrafo(g);
            printf("\n");
            break;

        case 3://busca em profundidade
            printf("1-recursiva\n2-iterativa\n");
            int escolha;
            scanf("%d", &escolha);
            if (escolha == 1) {
                printf("Numero de componentes conexas: %d\n", buscaProfundidadeRecursiva(g));
            } else if (escolha == 2) {
                printf("Numero de componentes conexas: %d\n", buscaProfundidadeIteratira(g));
            } else {
                printf("Entrada invalida!\n");
            }
            break;
        
        default:
            printf("Entrada invalida!\n");
            break;
        }
    }
    
}