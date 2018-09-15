#include <stdio.h>
#include "common.h"
#include "tree.h"
int main() {
	Tree *tree = initTree();
	tree->compare = &compareInt;
	int treeArray[10] = {12, 25, 36, 20, 15, 16, 10, 8, 5, 3};
	for(int i = 0;i < 10; ++i) {
		addNode(tree, &treeArray[i]);
	}
	deleteNode(tree, tree->root, &treeArray[1]);
	preOrderTraverse(tree->root);
}