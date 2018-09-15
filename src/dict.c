#include "dict.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static dictEntry HS_DELETED_ITEM = { NULL, NULL };

dictht *
createDict() {
    return newDict(HT_INITIAL_BASE_SIZE);
}

dictht*
newDict(const int hsSize) {
    dictht *dictht;
    if ((dictht = zmalloc(sizeof(*dictht))) == NULL) {
        return NULL;
    }

    dictht->size = hsSize;
    dictht->count = 0;
    dictht->table = calloc((size_t)dictht->size, sizeof(dictEntry *));
    return dictht;
}

int *
dictAdd(dictht *dict, void *key, void *val) {
    const int resize_rate = dict->count * 100 / dict->size;
    if (resize_rate > 70) {
        resize_up(dict);
    }

    dictEntry *entry = newEntry(key, val);
    int index = ht_get_hash(entry->key, dict->size, 0);
    dictEntry *curEntry = dict->table[index];
    int i = 1;
    while (curEntry != NULL) {
        if (curEntry != &HS_DELETED_ITEM && strcmp((char *)curEntry->key, (char *)key) == 0) {
            // 如果已经存在了同样的键，则覆盖它的值
            deleteEntry(curEntry);
            dict->table[index] = entry;
            return DICT_OK;
        }
        index = ht_get_hash(entry->key, dict->size, i);
        curEntry = dict->table[index];
        i ++;
    }
    dict->table[index] = entry;
    printf("元素 %s, index = %d\n", (char*)key, index);
    dict->count ++;
    return DICT_OK;
}

char *
dictSearch(dictht *dict, const char *key) {
    int index = ht_get_hash(key, dict->size, 0);
    int findHashIndex = 0;
    dictEntry *curEntry = dict->table[index];
    while(curEntry != NULL) {
        if (curEntry != &HS_DELETED_ITEM) {
			if (strcmp((char*)curEntry->key, key) == 0) {
				return (char *)curEntry->value;
			}
        }
        findHashIndex ++;
        index = ht_get_hash(key, dict->size, findHashIndex);
        curEntry = dict->table[index];
    }
    return NULL;
}

void dictDeleteKey(dictht *dict, const char *key) {
    const int resize_rate = dict->count * 100 / dict->size;
    if (resize_rate < 10) {
        resize_down(dict);
    }

    int index = ht_get_hash(key, dict->size, 0);
    int findHashIndex = 0;
    dictEntry *curEntry = dict->table[index];
    while(curEntry != NULL) {
        if (curEntry != &HS_DELETED_ITEM) {
            if (strcmp((char *)curEntry->key, key) == 0) {
                // 释放空间
                deleteEntry(curEntry);
                // 标记该位置已被删除
                dict->table[index] = &HS_DELETED_ITEM;
            }
        }
        findHashIndex ++;
        index = ht_get_hash(key, dict->size, findHashIndex);
        curEntry = dict->table[index];
    }
    dict->count --;
}

dictEntry *
newEntry(void *key, void *value) {
    dictEntry *item;
    item = zmalloc(sizeof(*item));
    item->key = key;
    item->value = value;
    return item;
}

void
deleteEntry(dictEntry *entry) {
    // free(entry->key);
    // free(entry->value);
    free(entry);
}

// 使用 rehash 的方式
int 
ht_get_hash(const char* s, const int num_buckets, const int attempt) {
    const int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
    const int hash_b = ht_hash(s, HT_PRIME_2, num_buckets);
    return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

int
ht_hash(const char* s, const int a, const int m) {
    const int len_s = strlen(s);
    long hash = 0;
    for(int i = 0; i < len_s; ++i) {
        long pw = 1;
        for(int j = 0; j < (len_s - (i+1)); ++j) {
            pw = a * pw; 
        }
        hash += pw * s[i];
        hash = hash % m;
    }
    return (int)hash;
}

void
resize_up (dictht *dict) {
    const int new_size = dict->size * 2;
    dictReSize(dict, new_size);
}

void
resize_down (dictht *dict) {
    const int new_size = dict->size / 2;
    dictReSize(dict, new_size);
}

void
dictReSize(dictht *dict, const int reSize) {
    if (reSize < HT_INITIAL_BASE_SIZE) {
        return;
    }
    dictht *tempDict = newDict(reSize);
    for(int i = 0; i < dict->size; ++i) {
        dictEntry *entry = dict->table[i];
        if (entry != NULL && entry != &HS_DELETED_ITEM) {
            dictAdd(tempDict, entry->key, entry->value);
        }
    }

    const int temp_size = dict->size;
    dict->size = tempDict->size;
    tempDict->size = temp_size;
    
    dictEntry **temp_entry = dict->table;
    dict->table = tempDict->table;
    tempDict->table = temp_entry;
    deleteDict(tempDict);
}

void deleteDict(dictht *dict) {
    for(int i = 0; i < dict->size; i++) {
        deleteEntry(dict->table[i]);
    }
    free(dict);
}
