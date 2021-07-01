#include <stdlib.h>
#include <stdio.h>
#include "GRAPHmatrix.h"

Graph GRAPHinit(int V){
    Graph G = malloc(sizeof *G);
    G->V = V;
    G->A = 0;
    G->adj = MATRIXint(V, V, 0);
    return G;
}

static int **MATRIXint(int r, int c, int val){
    int **m = malloc(r * sizeof(int*));
    for(vertex i=0; i<r; i++)
        m[i] = malloc(c * sizeof(int));
    for(vertex i=0; i<r; i++)
        for(vertex j=0; j<c; j++)
            m[i][j] = val;
    return m;
}

void GRAPHinsertArc(Graph G, vertex v, vertex w){
    if(G->adj[v][w] == 0){
        G->adj[v][w] = 1;
        G->A++;
    }
}

void GRAPHremoveArc(Graph G, vertex v, vertex w){
    if(G->adj[v][w] == 1){
        G->adj[v][w] = 0;
        G->A--;
    }
}

void GRAPHshow(Graph G){
    for(vertex v=0; v<G->V; v++){
        printf("%2d: ", v);
        for(vertex w=0; w<G->V; w++)
            if(G->adj[v][w] == 1)
                printf(" %2d", w);
        printf("\n");
    }
}

int isSink[1000];
void GRAPHisSink(Graph G){
    for(vertex v = 0; v<G->V; v++){
        isSink[v] = 1;
        for(int w = 0; w<G->V; w++){
            if(G->adj[v][w] == 1){
                isSink[v] = 0;
                break;
            }
        }
        if(isSink[v] == 1){
            isSink[v] = 0;
            for(int w = 0; w<G->V; w++)
                if(G->adj[w][v] == 1){
                    isSink[v] = 1;
                    break;
                }
        }
    }
}

/**
 *    0 1 2 3
 * 0: 0 1 0 1
 * 1: 0 0 0 0
 * 2: 1 0 1 0
 * 3: 1 1 1 1
 */