/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved. 
 * Description: 362. 敲击计数器
 * link: https://leetcode-cn.com/problems/design-hit-counter/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

/*typedef struct {
    int ts;
    long hits;
    UT_hash_handle hh;
}HashNode;*/

/*int IntCmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}*/

/*typedef struct {
    int cts;
    long hits;
    HashNode *hash;
} HitCounter;*/

void ReleaseHashNode(HitCounter* obj)
{
    HashNode *cur, *tmp;
    HASH_ITER(hh, obj->hash, cur, tmp) {
        HASH_DEL(obj->hash, cur);
        free(cur);
    }
}

/** Initialize your data structure here. */

HitCounter* hitCounterCreate() {
    HitCounter *hc = malloc(sizeof(HitCounter));
    hc->cts = 0;
    hc->hits = 0;
    hc->hash = NULL;
    return hc;
}

/** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
void hitCounterHit(HitCounter* obj, int timestamp) {

    HashNode *node;
    HASH_FIND_INT(obj->hash, &timestamp, node);
    if (node == NULL) {
        node = malloc(sizeof(HashNode));
        node->ts = timestamp;
        node->hits  = 1;
        HASH_ADD_INT(obj->hash, ts, node);
        HASH_SORT(obj->hash, QsortCmpArrayAscOrder);
    } else {
        node->hits += 1;
    }
    obj->hits += 1;
    obj->cts = timestamp;
}

/** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
int hitCounterGetHits(HitCounter* obj, int timestamp) {

    int begin = timestamp - 5 * 60;
    if (begin <= 0) {
        return obj->hits;
    }

    HashNode *cur, *tmp;    
    HASH_ITER(hh, obj->hash, cur, tmp) {
        if (cur->ts <= begin) {
            obj->hits -= cur->hits;
            HASH_DEL(obj->hash, cur);
            free(cur);
        } else {
            break;
        }
    }

    return obj->hits;
}

void hitCounterFree(HitCounter* obj) {
    ReleaseHashNode(obj);
    free(obj);
}

/**
 * Your HitCounter struct will be instantiated and called as such:
 * HitCounter* obj = hitCounterCreate();
 * hitCounterHit(obj, timestamp);
 
 * int param_2 = hitCounterGetHits(obj, timestamp);
 
 * hitCounterFree(obj);
*/