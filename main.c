#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"
#include "profundidade.h"
#include "largura.h"
#include "topologica.h"
#include "prim.h"
#include "dijkstra.h"
#include "estatisticas.h"

int main() {
    Grafo* g = NULL;
    int escolha = 0;
    int arquivo;
    int origem, destino;
    system("clear");

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

            if (g) {
                printf("Grafo carregado com sucesso!\n");
            }
            break;

        case 2://mostrar grafo
            mostrarGrafo(g);
            printf("\n");
            break;

        case 3://busca em profundidade
            printf("1-recursiva\n2-iterativa\n");
            scanf("%d", &escolha);
            if (escolha == 1) {
                printf("Numero de componentes conexas: %d\n", buscaProfundidadeRecursiva(g, 1));
            } else if (escolha == 2) {
                printf("Numero de componentes conexas: %d\n", buscaProfundidadeIteratira(g));
            } else {
                printf("Entrada invalida!\n");
            }
            break;
        
        case 4:
            printf("1-busca em largura\n2-distancia a partir de um vertice origem\n");
            scanf("%d", &escolha);
            if (escolha == 1) {
                buscaEmLargura(g);
            } else if (escolha == 2) {
                printf("Distancia do vertice: ");
                scanf("%d", &escolha);
                distanciaDoVertice(g, escolha);
            } else {
                printf("Entrada invalida!\n");
            }
            break;
            
        case 5://TODO: detectar ciclo se der tempo
            ordemTopologica(g);
            break;

        case 6:
            printf("Peso total da arvore: %d\n\n", prim(g));
            break;
        
        case 7:
            printf("Digite o vertice de origem: "); scanf("%d", &origem);
            printf("Digite o vertice de destino: "); scanf("%d", &destino);
            int temp = dijkstra(g, origem, destino);
            if (temp == -1) {
                printf("Nao ha um caminho entre os dois vertices informados!\n");
            } else {
                printf("Distancia: %d\n", temp);
            }
            break;
        
        case 8:
            if (!g) {
                printf("Grafo nao carregado!\n");
                break;
            }
            printf("Numero de vertices: %d\nNumero de arestas: %d\n\n", g->V, g->A);
            
            printf("Conexo? ");
            if (conexo(g)) {
                printf("sim\n\n");
            } else {
                printf("nao\n\n");
            }

            printf("Contem ciclo? ");
            if (temCiclo(g)) {
                printf("sim\n\n");
            } else {
                printf("nao\n\n");
            }

            grauDosVertices(g);
            printf("\n");

            printf("Densidade do grafo: %f\n\n", (float)(g->A) / (g->V * (g->V-1)));

            printf("Direcionado? ");
            if (direcionado(g)) {
                printf("sim\n\n");
            } else {
                printf("nao\n\n");
            }
            
            break;

        case 9:
            break;

        default:
            printf("Entrada invalida!\n");
            break;
        }

        if (escolha != 9) {
            printf("Pressione enter para continuar");
            getchar();
            getchar();
            system("clear");
        }
        
    }

    desalocaGrafo(g);
    
}