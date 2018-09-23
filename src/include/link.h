#ifndef __LINK_H
#define __LINK_H

#include "common.h"
typedef struct listNode {
    struct listNode *prev;
    struct listNode *next;
    void *value;
} listNode;

typedef struct list {
    listNode *head;
    listNode *tail;
    unsigned long len;
    int (*match)(void *ptr, void *key);
    void (*free)(void *ptr);
} list;

typedef struct listIter {
    // 当前迭代到的节点
    listNode *next;
    // 迭代的方向
    int direction;

} listIter;

list *listCreate(void);
list *listInsertNode(list *list, listNode *oldNode, void *value, int after);
list *listAddNodeToHead(list *list, void *value);
list *listAddNodeToTail(list *list, void *value);
void listDelNode(list *list, listNode *node);
listNode *listSearchKey(list *list, void *key);
enum STATE createNode(listNode **node, void *val);
void removeNode(listNode *node);
listIter *listGetIterator(list *list, int direction);
void listReleaseIterator(listIter *iter);
listNode *listNext(listIter *iter);

// 从表头向表尾进行迭代
#define AL_START_HEAD 0
// 从表尾到表头进行迭代
#define AL_START_TAIL 1

#endif