#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void showPath(int *p, int origem, int destino, float distancia) {
    if(origem == destino) {
        printf("v%d\n", origem);
        return;
    }
    if(distancia >= INT_MAX/2) {
        printf("Nao existe caminho entre os vertices\n");
        return;
    }

    int i = destino;
    printf("v%d -> ", i);
    while(i != origem) {
        i = p[i];
        if(i != origem) printf("v%d -> ", i);
        else printf("v%d\n", i);
    }
    printf("Distancia: %.2f\n", distancia);
}

void relaxa(int origem, Adj *adj, float *d, int *p) {
   int destino = adj->vf;
   float peso = adj->peso;

   if(d[origem] + peso < d[destino]){
        d[destino] = d[origem] + peso;
        p[destino] = origem;
   }
}

int menorAberto(Grafo *g, boolean *aberto, float *d) {
    float menor = INT_MAX;
    int menorIndice = -1;

    for(int i = 0; i < g->vertices; i++) {
        if(aberto[i] && d[i] < menor) {
            menor = d[i];
            menorIndice = i;
        }
    }

    return menorIndice;
}

boolean existeAberto(Grafo *g, boolean *aberto) {
    for(int i = 0; i < g->vertices; i++) {
        if(aberto[i]) return true;
    }
    return false;
}

void inicializaDijkstra(Grafo *g, float *d, int *p, boolean *aberto) {
    for (int i = 0; i < g->vertices; i++) {
        d[i] = INT_MAX/2;
        aberto[i] = true;
        p[i] = -1;
    }
}

boolean dijkstra(Grafo *g, int origem, int destino) {
    if(!g) return false;
    if(origem >= g->vertices || destino >= g->vertices) return false;
    if(origem < 0 || destino < 0) return false;

    float *d = (float *) malloc(g->vertices*sizeof(float));                 // vetor de distancias
    int *p = (int *) malloc(g->vertices*sizeof(int));                       // vetor de antecessores
    boolean *aberto = (boolean *) malloc(g->vertices*sizeof(boolean));      // abertos / fechados

    inicializaDijkstra(g, d, p, aberto);

    d[origem] = 0;

    while(existeAberto(g, aberto)) {
        int u = menorAberto(g, aberto, d);
        aberto[u] = false;
        Adj *adj = g->v[u].cab;
        while(adj) {
            relaxa(u, adj, d, p);
            adj = adj->next;
        }
    }

    showPath(p, origem, destino, d[destino]);
    freeDijkstra(d, p, aberto);

    return true;
}

void freeDijkstra(float *d, int *p, boolean *aberto) {
    if(d) free(d);
    if(p) free(p);
    if(aberto) free(aberto);
}