#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "../lib/helper.h"
#include "../lib/sort.h"
#include "../lib/tree.h"
int main() {
	int array[] = {12, 25, 36, 20, 15, 16, 10, 8, 5, 3};
	// 排序相关
	chose_sort(array, ARR_LENGTH);
	bubble_sort(array, ARR_LENGTH);
	insert_sort(array, ARR_LENGTH);
	no_swap_insert_sort(array, ARR_LENGTH);
	shell_sort(array, ARR_LENGTH);
	merge_sort(array, ARR_LENGTH);
	quick_sort(array, ARR_LENGTH);

	// 二叉树相关
	Tree *tree = initTree();
	tree->compare = &compareInt;
	int treeArray[10] = {12, 25, 36, 20, 15, 16, 10, 8, 5, 3};
	for(int i = 0;i < 10; ++i) {
		addNode(tree, &treeArray[i]);
	}
	// Node *findNode = search(tree, &array[5]);
	deleteNode(tree, tree->root, &treeArray[1]);
	preOrderTraverse(tree->root);
	getchar();
	return 0;
}