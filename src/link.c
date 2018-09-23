#include <stdlib.h>
#include "link.h"
#include "common.h"

// 初始化双端链表
// 注意：
//  链表头部的前置节点为 NULL
//  链表尾部的后置节点为 NULL
list *
listCreate(void) {
    list *linkList;
    if ((linkList = zmalloc(sizeof(*linkList))) == NULL)
        return NULL;
    linkList->head = linkList->tail = NULL;
    linkList->match = NULL;
    // free 函数可用于统一释放各种类型的内存
    linkList->free = NULL;
    linkList->len = 0;
    return linkList;
}

/*
* 将元素插入到指定节点的前方或后方
* after = 0 插入到元素前方
* after = 1 插入到元素后方
*/
list *
listInsertNode(list *list, listNode *oldNode, void *value, int after) {
    listNode *newNode;
    if ((newNode = zmalloc(sizeof(*newNode))) == NULL) {
        return NULL;
    }
    newNode->value = value;
    if (after == 0) {
        // 代表元素插入到链表头部
        if (oldNode->prev == NULL) return listAddNodeToHead(list, value);
        newNode->next = oldNode;
        newNode->prev = oldNode->prev;
        oldNode->prev->next = newNode;
        oldNode->prev = newNode;
    } else {
        if (oldNode->next == NULL) return listAddNodeToTail(list, value);
        newNode->next = oldNode->next;
        newNode->prev = oldNode;
        oldNode->next->prev = newNode;
        oldNode->next = newNode;
    }
    list->len ++;
    return list;
}

list *
listAddNodeToHead(list *list, void *value) {
    listNode *newNode;
    if ((newNode = zmalloc(sizeof(*newNode))) == NULL) {
        return NULL;
    }
    newNode->value = value;
    if (list->len == 0) {
        list->head = list->tail = newNode;
        newNode->prev = newNode->next = NULL;
    } else {
        newNode->prev = NULL;
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
    list->len ++;
    return list;
}

// same to listInsertNode
list *
listAddNodeToTail(list *list, void *value) {
    listNode *newNode;
    if ((newNode = zmalloc(sizeof(*newNode))) == NULL) {
        return NULL;
    }
    newNode->value = value;
    if (list->len == 0) {
        list->head = list->tail = newNode;
        newNode->prev = newNode->next = NULL;
    } else {
        newNode->next = NULL;
        newNode->prev = list->tail;
        list->tail->next = newNode;
		list->tail = newNode;
    }
    list->len ++;
    return list;
}

void
listDelNode(list *list, listNode *node) {
    if (node->prev == NULL) {
        // 下一个元素将成为头节点
        list->head = node->next;
    } else {
        node->prev->next = node->next;
    }

    if (node->next == NULL) {
        list->tail = node->prev;
    } else {
        node->next->prev = node->prev;
    }

    if (list->free) list->free(node->value);

    zfree(node);
    list->len --;
}

listNode *
listSearchKey(list *list, void *key) {
    listIter *iter = listGetIterator(list, AL_START_HEAD);
    listNode *curNode;
    while((curNode = listNext(iter)) != NULL) {
        if (list->match == NULL) {
            if (curNode->value == key) {
                listReleaseIterator(iter);
                return curNode;
            }
        } else {
            if (list->match(curNode->value, key)) {
                listReleaseIterator(iter);
                return curNode;
            }
        }
    }
    listReleaseIterator(iter);
    return NULL;
}

listIter *listGetIterator(list *list, int direction) {
    listIter *iter;
    if ((iter = zmalloc(sizeof(*iter))) == NULL) {
        return NULL;
    }
	iter->next = (direction == AL_START_HEAD) ? list->head : list->tail;
    iter->direction = direction;
    return iter;
}

listNode *listNext(listIter *iter) {
    listNode *curNode = iter->next;
    if (curNode != NULL) {
        iter->next = (iter->direction == AL_START_HEAD) ? curNode->next : curNode->prev;
    }
    return curNode;
}

// 创建新节点
enum STATE createNode(listNode **node, void *val) {
    listNode *out;
    if ((out = zmalloc(sizeof(*out))) == NULL) {
        return MALLOC_ERR;
    }

    out->prev = out->next = NULL;
    out->value = val;
    *node = out;
    return OK;
}

// 删除一个节点
void removeNode(listNode *node) {
    listNode *prev = node->prev;
    if (prev != NULL) {
        node->prev = NULL;
        prev->next = NULL;
    }
    free(node);
}

void listReleaseIterator(listIter *iter) {
    zfree(iter);
}