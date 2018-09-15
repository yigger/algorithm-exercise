#include <stdio.h>
#include "common.h"
#include "link.h"

int main() {
  list *list;
	int linkArray[10] = {12, 25, 36, 20, 15, 16, 10, 8, 5, 3};
	list = listCreate();
	for(int i = 0;i < 10; ++i) {
		// 在尾部追加元素
		listAddNodeToTail(list, &linkArray[i]);
	}

	int insertVal = 200;
	// 在头部追加元素、尾部追加元素、删除指定元素
	listAddNodeToHead(list, &insertVal);
	listAddNodeToTail(list, &insertVal);
	listDelNode(list, listSearchKey(list, &insertVal));

	// 指定元素前后插入新元素
	int insertAfterVal = 3000;
	listInsertNode(list, listSearchKey(list, &linkArray[0]), &insertAfterVal, 0);
	listInsertNode(list, listSearchKey(list, &linkArray[9]), &insertAfterVal, 1);

	// 遍历链表结果
	listNode *node = list->head;
	while(node != NULL) {
		printf("%d ", (*(int *)node->value));
		node = node->next;
	}
	printf("\n元素寻找结果 - %d\n", (*(int *) listSearchKey(list, &insertVal)->value));
}