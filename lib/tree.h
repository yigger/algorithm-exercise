#ifndef __TREE_H
#define __TREE_H

// 二叉树
typedef struct Node {
    void *value;
    struct Node *left;
    struct Node *right;
} Node;


typedef struct Tree {
    int height;
    int nodeSize;
    struct Node *root;

	// 比较函数
	int(*compare)(void *, void *);
} Tree;

Tree *initTree();
Tree *addNode(Tree *tree, void *value);
Node *SearchInsertNewNode(Tree *tree, Node *root, Node *newNode);
void preOrderTraverse(Node *node);
#endif