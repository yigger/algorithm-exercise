#ifndef __TREE_H
#define __TREE_H

#define getNodeValue(node) ((*(int *) ((node)->value)))

// 二叉树
typedef struct Node {
    void *value;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
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
Node* insert(Tree *tree, Node* node, void *key);
Tree *deleteNode(Tree *tree, Node *node);
// 查找结点
Node *search(Tree const *tree, void *value);
// 先序遍历
void preOrderTraverse(Node *node);



#endif