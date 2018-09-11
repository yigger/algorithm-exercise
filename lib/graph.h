#ifndef __GRAPH_H
#define __GRAPH_H

typedef char vertexType;
typedef enum STATE StatusCode;

// 边
typedef struct EdgeNode {
    int adjvex;
    struct EdgeNode *next;
} EdgeNode;

// 顶点节点
typedef struct {
    vertexType vertex;
    EdgeNode *firstedge;
} VertexNode;

typedef struct Graph {
    VertexNode **list;
    // 顶点数
    int nodeSize;
    // 边数
    int edgeSize;
} Graph;

StatusCode createGraph(Graph *g);
StatusCode addEdge(Graph *g);


#endif