/**
 * Grafo representado por matriz de adjacências
 * Autor: Pedro Henrique (seguindo livro do prof. Paulo Feofiloff)
 * 
 * Disciplina de Algoritmos para Grafos
 * Professor: Alex Pontes
 */
#include <stdbool.h>

// Tipo de dado -----------------------------------------------------------------------------------
/**
 * Definição do tipo de dado de um vértice
 */
#define vertex int


// Representação por lista ------------------------------------------------------------------------
/**
 * Um grafo representado por matriz é literalmente uma matriz de booleanos
 * onde as linhas são os vértices e as colunas são os possíveis arcos do
 * grafo. O que define se existe um arco ou não será uma posição marcada v-w
 * marcada com "1".
 * 
 * matriz[v][w] = 0; se v-w não é um arco
 * matriz[v][w] = 1; se v-w é um arco
 * 
 * Representação
 * Arcos v-w                Arcos por matriz
 * 0-1                            0 1 2 3 
 * 0-2                         0: 0 1 1 0
 * 1-2                         1: 0 0 1 0
 * 2-0                         2: 1 0 0 1
 * 2-3                         3: 0 0 0 0
 */


// Estrutura --------------------------------------------------------------------------------------
struct graph{
    int V;      // Quantidade de vértices
    int A;      // Quantidade de arcos
    int **adj;  // Matriz de adjacência
};
typedef struct graph *Graph; // Tipo de dado abstrato de um grafo


// Funções ----------------------------------------------------------------------------------------
// Funções básicas --------------------------------------------------------------------------------
/**
 * Inicial um grafo com V vértices e nenhum arco
 */
Graph GRAPHinit(int V);

/**
 * Aloca uma matriz com "r" linhas e "c" colunas e preenche cada
 * posição com "val" valores.
 */
static int **MATRIXint(int r, int c, int val);

/**
 * Insere um arco v-w no grafo "G".
 */
void GRAPHinsertArc(Graph G, vertex v, vertex w);

/**
 * Remove o arco v-w do grafo "G".
 */
void GRAPHremoveArc(Graph G, vertex v, vertex w);

/**
 * Exibe o grafo "G" na tela.
 */
void GRAPHshow(Graph G);


// Estruturas de dados para grafos: Exercício 1 ---------------------------------------------------
/**
 * Calcula um vetor global isSink[] indexado pelos vértices
 * e com o valor "1" indicando que o vértice é sorvedouro
 * ou "0" caso não seja.
 */
void GRAPHisSink(Graph G);

/**
 * Calcula um vetor global isSource[] indexado pelos vértices
 * e com o valor "1" indicando que o vértice é fonte ou "0"
 * caso não seja.
 */
void GRAPHisSource(Graph G);

/**
 * Calcula o grau de entrada de um vértice "v" do grafo "G"
 */
int GRAPHindeg(Graph G, vertex v);

/**
 * Calcula o grau de saída de um vértice "v" do grafo "G"
 */
int GRAPHoutdeg(Graph G, vertex v);

/**
 * Calcula o grau de entrada de todos os vértices do grafo "G"
 * e armazena no vetor "indeg[]".
 */
void GRAPHindegs(Graph G, int indeg[]);

/**
 * Calcula o grau de saída de todos os vértices do grafo "G"
 * e armazena no vetor "outdeg[]".
 */
void GRAPHoutdegs(Graph G, int outdeg[]);

/**
 * Desaloca o grafo e libera a memória ocupada por ele.
 */
void GRAPHdestroy(Graph G);

/**
 * Verifica se os grafos "G" e "H" são iguais
 */
bool GRAPHequal(Graph G, Graph H);
