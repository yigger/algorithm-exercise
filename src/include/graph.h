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
    int V;
    // 边数
    int E;
} Graph;

StatusCode createGraph(Graph *g, int v);
StatusCode addEdgeToGraph(Graph *g, vertexType src, vertexType dest);
StatusCode createEdge(EdgeNode *node, vertexType data);


#endif