#define true 1
#define false 0
typedef int boolean;

typedef struct adj {
    int vf;                 // vertice de destino
    float peso;             // peso da aresta
    struct adj *next;       // next é o ponteiro para o próximo elemento da lista
} Adj;

typedef struct vertice {
    Adj *cab;               // cabeça da lista de adjacências
    int indice;             // índice do vértice
} Vertice;

typedef struct grafo {
    int vertices;           // numero de vertices
    int arestas;            // numero de arestas
    Vertice *v;             // vetor de vertices
} Grafo;