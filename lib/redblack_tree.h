#ifndef __REDBLACK_TREE__
#define __REDBLACK_TREE__

typedef struct rbNode {
    void *value;
    struct rbNode *left;
    struct rbNode *right;
    int color;
} rbNode;

typedef struct RedBlackTree{
    // 根节点
    rbNode *root;

    // 节点数量
    int nodeSize;

    // 比较函数
    int(*compare)(void *, void *);
} RedBlackTree;

RedBlackTree *initTree();
static rbNode *initNode();
rbNode *addNode(void *key, void *val);
rbNode *deleteNode(void *key);
rbNode *searchNode(void *key);

#endif