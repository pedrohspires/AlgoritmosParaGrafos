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

int isSource[1000];
void GRAPHisSource(Graph G){
    for(vertex v = 0; v<G->V; v++){
        isSource[v] = 1;
        for(vertex w = 0; w<G->V; w++){
            if(G->adj[w][v] == 1){
                isSource[v] = 0;
                break;
            }
        }
        if(isSource[v] == 1){
            isSource[v] = 0;
            for(vertex w = 0; w<G->V; w++){
                if(G->adj[v][w] == 1){
                    isSource[v] = 1;
                    break;
                }
            }
        }
    }
}

int GRAPHindeg(Graph G, vertex v){
    int count = 0;
    for(vertex vG = 0; vG<G->V; vG++){
        for(vertex w = 0; w<G->V; w++){
            if(G->adj[w][vG] == 1 && v == vG)
                count++;
        }
    }
    return count;
}

int GRAPHoutdeg(Graph G, vertex v){
    int count = 0;
    for(vertex vG = 0; vG<G->V; vG++){
        for(vertex w = 0; w<G->V; w++){
            if(G->adj[vG][w] == 1 && v == vG)
                count++;
        }
    }
    return count;
}