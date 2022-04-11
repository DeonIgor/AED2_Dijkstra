#include <stdio.h>
#include <stdlib.h>

Grafo *createGrafo(int numVertices) {
    Grafo *g = (Grafo *) malloc(sizeof(Grafo));

    g->vertices = numVertices;
    g->arestas = 0;
    g->v = (Vertice *) malloc(g->vertices * sizeof(Vertice));

    for (int i = 0; i < g->vertices; i++) {
        g->v[i].cab = NULL;
        g->v[i].indice = i;
    }

    return g;
}

boolean addAresta(Grafo *g, int vi, int vf, float peso) {
    if(!g) return false;
    if(vi < 0 || vi >= g->vertices) return false;
    if(vf < 0 || vf >= g->vertices) return false;

    Adj *novaAdj = (Adj *) malloc(sizeof(Adj));
    novaAdj->vf = vf;
    novaAdj->peso = peso;

    novaAdj->next = g->v[vi].cab;
    g->v[vi].cab = novaAdj;
    g->arestas++;

    return true;
}

boolean printGrafo(Grafo *g) {
    if(!g) return false;

    printf("\n");
    printf("%d Vertices\n", g->vertices);
    printf("%d Arestas\n", g->arestas);
    for (int i = 0; i < g->vertices; i++) {
        Adj *adj = g->v[i].cab;
        printf("v%d -> ", i);
        while (adj != NULL) {
            printf("v%d(%.2f) ", adj->vf, adj->peso);
            adj = adj->next;
        }
        printf("\n");
    }
    return true;
}

void freeGrafo(Grafo *gr) {
    if(gr == NULL) return;
    for (int i = 0; i < gr->vertices; i++) {
        Adj *adj = gr->v[i].cab;
        while (adj != NULL) {
            Adj *aux = adj;
            adj = adj->next;
            free(aux);
        }
    }
    free(gr);
}