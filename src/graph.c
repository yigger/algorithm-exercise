#include "graph.h"
#include "helper.h"
#include <stdlib.h>

#define NODE_INIT_SIZE 16

StatusCode createGraph(Graph *g, int v) {
    if((g = zmalloc(sizeof(Graph*))) == NULL) {
        return MALLOC_ERR;
    }
    g->V = v;
    g->E = 0;
    g->list = zmalloc(sizeof(VertexNode) * v);
    for(int i = 0; i < v; ++i) {
        g->list[i].firstedge = NULL;
    }
    return OK;
}

// StatusCode addEdge(Graph *g, vertexType src, vertexType dest) {
    
// }

EdgeNode *
addNewNode(vertexType data) {
    EdgeNode *node;
    if((node = zmalloc(sizeof(EdgeNode *))) == NULL) {
        return NULL;
    }

    node->adjvex = data;
    node->next = NULL;
    return node;
}