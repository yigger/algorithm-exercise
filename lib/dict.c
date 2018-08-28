#include "./dict.h"
#include "./helper.h"
#include <stdlib.h>
#include <string.h>

dictht *
createDict() {
    dictht *dictht;
    if ((dictht = zmalloc(sizeof(*dictht))) == NULL) {
        return NULL;
    }

    dictht->table = NULL;
    dictht->size = 0;
    dictht->used = 0;
    return dictht;
}

int *
dictAdd(dictht *dict, void *key, void *val) {
    dictEntry *entry = dictAddRaw(dict, key);

    // if(!entry) return DICT_ERR;

    // entry->value = val;

    return DICT_OK;
}

dictEntry *
dictAddRaw(dictht *dict, void *key) {
    int index;
    dictEntry *entry;
    
    if ((index = _dictKeyIndex(key)) == -1) {
        return NULL;
    }

    entry = zmalloc(sizeof(*entry));
    // entry->next = dict->table[index];
    // dict->table[index] = entry;
    
    return entry;
}

// 计算哈希索引值
// len 字符串长度
static unsigned int
_dictKeyIndex(void *key) {
    unsigned int hash = 5381;
    char *buf = (char*)key;
    // printf("%c", buf);
    int len = strlen(buf);
    
    // while (len--)
    //     hash = ((hash << 5) + hash) + (*buf++); /* hash * 33 + c */
    return hash;
}
