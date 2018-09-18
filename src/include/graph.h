#ifndef __GRAPH_H
#define __GRAPH_H

typedef int vertexType;
typedef enum STATE StatusCode;

// 边
typedef struct EdgeNode {
    vertexType adjvex;
    struct EdgeNode *next;
} EdgeNode;

// 顶点节点
typedef struct {
    // vertexType data;
    EdgeNode *firstedge;
} VertexNode;

typedef struct Graph {
    VertexNode *list;
    // 顶点数
    int vertexSize;
    // 边数
    int edgeSize;
} Graph;

StatusCode createGraph(Graph **graph, int vertexSize);
StatusCode addEdgeToGraph(Graph *g, vertexType src, vertexType dest);
StatusCode createEdge(EdgeNode **edge, int dest);
int *iterator(const Graph * const graph, int dest, int type);
void destroyGraph(Graph *graph);
#endif