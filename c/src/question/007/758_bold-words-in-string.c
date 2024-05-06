/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 758. 字符串中的加粗单词
 * link: https://leetcode-cn.com/problems/bold-words-in-string/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "public.h"

bool IsContain(char* a, int al, char* b, int bl)
{
    if( al < bl) {
        return false;
    }

    for (int i = 0; i < bl; ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

void OutputBoldWord(char *str, int *idx, char *S, int b, int e)
{
    int index  = *idx;
    str[index++] = '<';
    str[index++] = 'b';
    str[index++] = '>';

    for (int i = b; i < e; ++i) {
        str[index++] = *(S + i);
    }

    str[index++] = '<';
    str[index++] = '/';
    str[index++] = 'b';
    str[index++] = '>';

    *idx = index;
}

#define MAX_VAL(a, b) ((a) > (b) ? (a) : (b))
char * boldWords(char ** words, int wordsSize, char * S){
    if ((words == NULL) || (wordsSize <= 0) || (S == NULL)) {
        return NULL;
    }

    int len = strlen(S);
    int idx = 0;
    char *bs = calloc(len * 6, sizeof(char));

    bool match = false;
    int b = 0;
    int e = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < wordsSize; ++j) {
            if (IsContain(S + i, len - i, words[j], strlen(words[j]))) {
                if (match == false) {
                    b = i;
                    e = i + strlen(words[j]);
                    match = true;
                } else {
                    e = GetMaxValue(e, i + strlen(words[j]));
                }
            }
        }

        if (match == true) {
            if (i == e) {
                match = false;
                OutputBoldWord(bs, &idx, S, b, e);
                bs[idx++] = *(S + i);
            }
        } else {
            bs[idx++] = *(S + i);
        }
    }

    if (match == true) {
        OutputBoldWord(bs, &idx, S, b, e);
    }

    return bs;
}