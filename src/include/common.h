#ifndef __COMMON_H
#define __COMMON_H
#include <stdlib.h>

enum STATE {
	OK = 0,
	MALLOC_ERR = 1,
	ALLOC_ERR = 2,
	ERROR = 3
};

void *zmalloc(size_t size);
void *zcalloc(size_t size);
void zfree(void *ptr);
#endif