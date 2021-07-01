#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "./GRAPHlist.h"

static link NEWnode(vertex w, link next){
    link a = malloc(sizeof(struct node));
    a->w = w;
    a->next = next;
    return a;
}

Graph GRAPHinit(int V){
    Graph G = malloc(sizeof(*G));
    G->V = V;
    G->A = 0;
    G->adj = malloc(V * sizeof(link));
    for(vertex v=0; v<G->V; v++)
        G->adj[v] = NULL;
    return G;
}

void GRAPHinsertArc(Graph G, vertex v, vertex w){
    for(link a = G->adj[v]; a != NULL; a = a->next)
        if(a->w == w)
            return;
    G->adj[v] = NEWnode(w, G->adj[v]);
    G->A++;
}

void GRAPHremoveArc(Graph G, vertex v, vertex w){
    link old = G->adj[v];
    if(old->w == w){
        G->adj[v] = old->next;
        free(old);
        return;
    }
    for(link a = old; a!=NULL; a = a->next){
        if(a->w == w){
            old->next = a->next;
            free(a);
            return;
        }
        old = a;
    }
}

void GRAPHshow(Graph G){
    for(vertex v = 0; v<G->V; v++){
        printf("%2d: ", v);
        for(link a = G->adj[v]; a!=NULL; a=a->next)
            printf("%2d", a->w);
        printf("\n");
    }
}

int isSink[1000];
void GRAPHisSink(Graph G){
    for(vertex v = 0; v<G->V; v++){
        isSink[v] = 0;
        if(G->adj[v] == NULL){
            for(vertex w = 0; w<G->V; w++){
                for(link a = G->adj[w]; a!=NULL; a = a->next){
                    if(a->w == v)
                        isSink[v] = 1;
                }
            }
        }
    }
}

int isSource[1000];
void GRAPHisSource(Graph G){
    for(vertex v = 0; v<G->V; v++){
        isSource[v] = 1;
        for(vertex w = 0; w<G->V; w++){
            for(link a = G->adj[w]; a!=NULL; a = a->next){
                if(a->w == v){
                    isSource[v] = 0;
                    break;
                }
            }
            if(isSource[v] == 0)
                break;
        }
        if(G->adj[v] == NULL){
            isSource[v] = 0;
        }
    }
}