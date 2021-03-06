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
        G->A--;
        return;
    }
    for(link a = old; a!=NULL; a = a->next){
        if(a->w == w){
            old->next = a->next;
            free(a);
            G->A--;
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

int GRAPHindeg(Graph G, vertex v){
    int count = 0;
    for(vertex vv = 0; vv<G->V; vv++){
        for(link a = G->adj[vv]; a!=NULL; a=a->next){
            if(a->w == v)
                count++;
        }
    }
    return count;
}

int GRAPHoutdeg(Graph G, vertex v){
    int count = 0;
    for(link a = G->adj[v]; a!=NULL; a = a->next)
        count++;
    return count;
}

void GRAPHindegs(Graph G, int indeg[]){
    for(vertex v = 0; v<G->V; v++)
        indeg[v] = GRAPHindeg(G, v);
}

void GRAPHoutdegs(Graph G, int outdeg[]){
    for(vertex v = 0; v<G->V; v++)
        outdeg[v] = GRAPHoutdeg(G, v);
}

void GRAPHdestroy(Graph G){
    for(vertex v = 0; v<G->V; v++){
        link a = G->adj[v], old;
        while(a != NULL){
            old = a;
            a = a->next;
            free(old);
            old = NULL;
        }
    }
    G->A = 0;
    G->V = 0;
    free(G->adj);
}

bool GRAPHequal(Graph G, Graph H){
    if(G->V != H->V || G->A != H->A)
        return false;
    for(vertex v = 0; v<G->V; v++){
        for(link a = G->adj[v]; a!=NULL; a = a->next){
            bool equal = false; // O arco pode estar em posi????es diferentes na lista
            for(link b = H->adj[v]; b!=NULL; b = b->next){ // passa por todos os arcos v-w do grafo H
                if(a->w == b->w){
                    equal = true;
                    break;
                }
            }
            if(!equal) // se n??o existir nenhum arco v-w em H, mas existir em G, retorna false
                return false;
        }
    }
    return true;
}