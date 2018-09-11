#include "./graph.h"
#include "./helper.h"
#include <stdlib.h>

#define NODE_INIT_SIZE 16

StatusCode createGraph(Graph *g) {
    if((g = zmalloc(sizeof(Graph*))) == NULL) {
        return MALLOC_ERR;
    }

    g->list = zmalloc(sizeof(VertexNode *) * NODE_INIT_SIZE);
    g->nodeSize = 0;
    g->edgeSize = 0;
    for(int i = 0; i < NODE_INIT_SIZE; ++i) {
        g->list[i] = NULL;
    }

    return OK;
}

StatusCode addEdge(Graph *g) {
    
}