#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "structures.h"
#include "dijkstra.h"
#include "grafos.h"

void menu() {
    printf("\n##############################\n");
    printf("# 1 - Adicionar Aresta\n");
    printf("# 2 - Imprimir Grafo\n");
    printf("# 3 - Calcular caminho minimo\n");
    printf("# 4 - Sair\n");
    printf("Sua Escolha: ");
}

int main() {

    char escolha = '\0';
    int grafoSize = 0,
        origem,
        destino;
    float peso;
    Grafo *gr;

    do{
        printf("\nInsira o tamanho do grafo (1-20): ");
        scanf("%d", &grafoSize);
    } while (1 > grafoSize || grafoSize > 20);
    gr = createGrafo(grafoSize);    

    do {
        menu();
        scanf(" %c", &escolha);

        switch (escolha){
        case '1':
            printf("Vertice de origem: ");
            scanf("%d", &origem);
            printf("Vertice de destino: ");
            scanf("%d", &destino);
            printf("Peso: ");
            scanf("%f", &peso);
            printf("\n");
            if(addAresta(gr, origem, destino, peso) == true)
                printf("Aresta adicionada com sucesso!\n");
            else {
                printf("Problema ao adicionar aresta!\n");
                printf("Os vertices validos sao de 0 a %d\n", gr->vertices - 1);
                printf("Somente pesos positivos sao admitidos!\n");
            }
            break;
        case '2':
            if(printGrafo(gr) == false)
                printf("Nao foi possivel imprimir grafo\n");
            break;
        case '3':
            printf("Vertice de origem: ");
            scanf("%d", &origem);
            printf("Vertice de destino: ");
            scanf("%d", &destino);
            printf("\n");
            if(dijkstra(gr, origem, destino) == false){
                printf("Nao foi possivel calcular o caminho!\n");
                printf("Os vertices validos sao de 0 a %d\n", gr->vertices - 1);
            }
            break;
        case '4':
            freeGrafo(gr);
            printf("\nObrigado por utilizar o programa!\n");
            printf("_________________________________________\n");
            break;
        default:
            printf("\n\nOpcao invalida!\n\n");
            break;
        }

    } while (escolha != '4');

    return 0;
}


