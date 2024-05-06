/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 358. K 距离间隔重排字符串
 * link: https://leetcode-cn.com/problems/rearrange-string-k-distance-apart/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/6/15.
 */

#include "public.h"

#define MAX_WORD_NUM 26

struct hash {
    char word;
    int times;
    int prePos;
};

struct hash g_hash[MAX_WORD_NUM];

int calcHashValue(char * s, int i)
{
    return s[i] - 'a';
}

void makeHash(char * s)
{
    int len = strlen(s);
    int index;

    for (int i = 0; i < len; i++) {
        index = calcHashValue(s, i);
        g_hash[index].times++;
        g_hash[index].word = s[i];
    }

    return;
}

int compHashTimes(const void* a, const void* b)
{
    return ((struct hash *)b)->times - ((struct hash *)a)->times;
}

void sortHashByTimes()
{
    qsort(g_hash, MAX_WORD_NUM, sizeof(struct hash), compHashTimes);
    return;
}

char getNextWord(int curPos, int k)
{
    int i;
    for (i = 0; i < MAX_WORD_NUM; i++) {
        if (g_hash[i].times == 0) {
            continue;
        }
        if (g_hash[i].prePos == -1 || (curPos - g_hash[i].prePos) >= k) {
            g_hash[i].prePos = curPos;
            g_hash[i].times--;
            return g_hash[i].word;
        }
    }

    return 0;
}

char * fillRetVal(char * s, int k){
    int times;
    int index;
    int nextIndex;
    int len = strlen(s);
    char word;
    char* retVal = (char*)malloc(sizeof(char) * (len + 1));
    memset(retVal, 0, sizeof(char) * (len + 1));

    int i;
    for (i = 0; i < len; i++) {
        word = getNextWord(i, k);
        if (word == 0) {
            break;
        }

        retVal[i] = word;
        sortHashByTimes();
    }

    retVal[len] = '\0';
    if (i < len) {
        retVal[0] = '\0';
    }
    return retVal;
}

char * rearrangeString(char * s, int k){
    if (s == NULL) {
        return NULL;
    }

    if (k <= 1) {
        return s;
    }

    memset(g_hash, 0, sizeof(struct hash) * MAX_WORD_NUM);
    makeHash(s);
    sortHashByTimes();

    int i = 0;
    for (i = 0; i < MAX_WORD_NUM; i++) {
        g_hash[i].prePos = -1;
    }

    return fillRetVal(s, k);
}