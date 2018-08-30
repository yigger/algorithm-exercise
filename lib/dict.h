#ifndef __DICT_H
#define __DICT_H

#define DICT_OK 0
#define DICT_ERR 1
#define HT_PRIME_1 151
#define HT_PRIME_2 156

typedef struct dictEntry {
    void *key;

    void *value;

    struct dictEntry *next;
} dictEntry;

typedef struct dictht {
    // 哈希表数组
    dictEntry **table;

    // 哈希表大小
    unsigned long size;

    unsigned long count;

    // 已有节点数
    unsigned long used;
} dictht;

// 计算给定键的哈希值
// #define dictHashKey(d, key) (d)->type->hashFunction(key)

dictht *createDict();
int *dictAdd(dictht *dict, void *key, void *val);
dictEntry *newEntry(void *key, void *value);
static int ht_hash(const char* s, const int a, const int m);
static int ht_get_hash(const char* s, const int num_buckets, const int attempt);
#endif