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
} Tree;

Tree *initTree();

#endif