/**
 * Grafo representado por lista de adjacências
 * Autor: Pedro Henrique (seguindo livro do prof. Paulo Feofiloff)
 * 
 * Disciplina de Algoritmos para Grafos
 * Professor: Alex Pontes
 */


// Tipo de dado -----------------------------------------------------------------------------------
/**
 * Definição do tipo de dado de um vértice
 */
#define vertex int


// Representação por lista ------------------------------------------------------------------------
/**
 * Um grafo representado por lista é um vetor indexado pelos vértices,
 * onde cada posição do vetor contém uma lista ligada em que cada nó
 * da lista é um arco v-w ("v" é o vértice índice do vetor e "w" é o
 * vértice final do arco)
 * 
 * Representação:
 * Arcos v-w           Arcos por lista
 * 0-1                 0[]->1->2
 * 0-2                 1[]->2
 * 1-2                 2[]->0->3
 * 2-0                 3[]
 * 2-3
 */

// Estrutura --------------------------------------------------------------------------------------
struct graph{
    int V;      // Quantidade de vértices
    int A;      // Quantidade de arcos
    link *adj;   // Vetor de lista adjacência
};
typedef struct graph *Graph; // Tipo de dado abstrato de um grafo


/**
 * Cada arco v-w é indicado por uma lista onde "v" é o índice do vetor
 * e "w" é um nó de uma lista representada por:
 */
typedef struct node *link; // Tipo de dado abstrato de um nó
struct node{
    vertex w;   // Vértice final do arco
    link next;  // Próximo vértice que também faz arco com "v"
};


// Funções ----------------------------------------------------------------------------------------
/**
 * Cria um novo nó
 */
static link NEWnode(vertex w, link next); // Função exclusiva da lista de adjacências

// Funções básicas --------------------------------------------------------------------------------
/**
 * Inicial um grafo com V vértices e nenhum arco
 */
Graph GRAPHinit(int V);

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
void GRAPHindegs(Graph G, int outdeg[]);

/**
 * Desaloca o grafo e libera a memória ocupada por ele.
 */
void GRAPHdestroy(Graph G);

/**
 * Verifica se os grafos "G" e "H" são iguais
 */
bool GRAPHequal(Graph G, Graph H);


// Estruturas de dados para grafos: Exercício 2 ---------------------------------------------------
/**
 * As funções deste exercício estão na área das funções básicas
*/