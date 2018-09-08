#ifndef __REDBLACK_TREE__
#define __REDBLACK_TREE__

#define Red 1
#define Black 0

typedef struct RedBlackNode {
    void *value;
    struct RedBlackNode *left;
    struct RedBlackNode *right;
    int color; // 红色： 1 黑色： 0
} RedBlackNode;

typedef struct RedBlackTree{
    // 根节点
    RedBlackNode *root;

    // 节点数量
    int nodeSize;

    // 比较函数
    int(*compare)(void *, void *);
} RedBlackTree;

RedBlackTree *initRedBlackTree();
static RedBlackNode *initNode(void *value);
RedBlackTree *rbAddNode(RedBlackTree *tree, void *val);
RedBlackNode *rbDeleteNode(RedBlackTree *tree);
RedBlackNode *dbSearchNode(RedBlackTree *tree);
static int isRed(RedBlackNode node);

#endif