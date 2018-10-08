#include <stdio.h>
#include "graph.h"
#include "common.h"
#include "deque.h"

#define NODE_INIT_SIZE 16
#define BFS 0
#define DFS 1

static int *_dfs(const Graph * const g, int dest, int *marked);
static int *_bfs(const Graph * const g, int dest, int *marked);

StatusCode createGraph(Graph **graph, int vertexSize) {
    Graph *g;
    if((g = zmalloc(sizeof(Graph*))) == NULL) {
        return MALLOC_ERR;
    }
    g->vertexSize = vertexSize;
    g->edgeSize = 0;
    g->list = zmalloc(sizeof(VertexNode *) * (g->vertexSize));
    for(int i = 0; i < g->vertexSize; ++i) {
        g->list[i].firstedge = NULL;
    }

    *graph = g;
    return OK;
}

StatusCode
addEdgeToGraph(Graph *g, vertexType src, vertexType dest) {
    if (src > g->vertexSize || dest > g->vertexSize) {
        return ERROR;
    }

    EdgeNode *destEdg;
    createEdge(&destEdg, dest);
    // 在当前顶点添加目标顶点到邻接表
    destEdg->next = g->list[src].firstedge;
    g->list[src].firstedge = destEdg;
    
    EdgeNode *srcEdg;
    createEdge(&srcEdg, src);
    // 在目标顶点添加当前顶点到邻接表
    srcEdg->next = g->list[dest].firstedge;
    g->list[dest].firstedge = srcEdg;
    return OK;
}

StatusCode
createEdge(EdgeNode **edge, int dest) {
    EdgeNode *node;
    if((node = zmalloc(sizeof(node))) == NULL) {
        return MALLOC_ERR;
    }
    node->adjvex = dest;
    node->next = NULL;
    *edge = node;
    return OK;
}

// 遍历
int *
iterator(const Graph * const graph, int dest, int type) {
    int *marked;
    if((marked = zcalloc(sizeof(int) * graph->vertexSize)) == NULL) {
        return NULL;
    }

    if (type == BFS) {
        return _dfs(graph, dest, marked);
    } else if (type == DFS) {
        return _bfs(graph, dest, marked);
    } else {
        free(marked);
        return NULL;
    }
}

// 深度优先搜索
static int *
_dfs(const Graph * const g, int dest, int *marked) {
    marked[dest] = 1;
    EdgeNode *edge = g->list[dest].firstedge;
    while(edge != NULL) {
        if (marked[edge->adjvex] == 0) {
            _dfs(g, edge->adjvex, marked);
        }
        edge = edge->next;
    }
    return marked;
}

// 广度优先搜索
static int *
_bfs(const Graph * const g, int dest, int *marked) {
    // 创建临时队列
    Deque *queue;
    createQueue(&queue);
    // 标记已访问的元素
    marked[dest] = 1;
    // 入队
    enqueue(queue, &dest);
    void *adj;
    while(!queueEmpty(queue)) {
        // 出队，获取目标顶点
        dequeue(queue, &adj);
        // 遍历目标顶点周围的顶点
        EdgeNode *edge = g->list[*(int*)adj].firstedge;
        while(edge != NULL) {
            if (marked[edge->adjvex] == 0) {
                marked[edge->adjvex] = 1;
                enqueue(queue, &edge->adjvex);
            }
            edge = edge->next;
        }
    }
    return marked;
}

void destroyGraph(Graph *graph) {
    free(graph->list);
    free(graph);
}