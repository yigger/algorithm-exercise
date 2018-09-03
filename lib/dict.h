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

    // 已用元素节点
    unsigned long count;
} dictht;


dictht *createDict();
int *dictAdd(dictht *dict, void *key, void *val);
char *dictSearch(dictht *dict, const char *key);
void dictDelete(dictht *dict, const char *key);
void deleteEntry(dictEntry *entry);
dictEntry *newEntry(void *key, void *value);
static int ht_hash(const char* s, const int a, const int m);
static int ht_get_hash(const char* s, const int num_buckets, const int attempt);
#endif