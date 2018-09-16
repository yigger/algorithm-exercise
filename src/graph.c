#include <stdio.h>
#include "graph.h"
#include "common.h"

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

StatusCode
addEdgeToGraph(Graph *g, vertexType src, vertexType dest) {
    EdgeNode destEdg;
    if (src > g->V || dest > g->V) {
        return ERROR;
    }

    createEdge(&destEdg, dest);
    printf("dest -> %d\n", destEdg.adjvex);
    // 在当前顶点添加目标顶点到邻接表
    // destEdg.next = g->list[src].firstedge;
    // g->list[src].firstedge = &destEdg;
    
    // EdgeNode srcEdg;
    // createEdge(&srcEdg, src);
    // // 在目标顶点添加当前顶点到邻接表
    // srcEdg.next = g->list[dest].firstedge;
    // g->list[dest].firstedge = &srcEdg;
    return OK;
}

StatusCode
createEdge(EdgeNode *node, vertexType data) {
    printf("in -> %d\n", data);
    if((node = zmalloc(sizeof(EdgeNode *))) == NULL) {
        return MALLOC_ERR;
    }
    node->adjvex = data;
    node->next = NULL;
    return OK;
}