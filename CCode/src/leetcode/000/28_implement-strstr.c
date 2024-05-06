/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 28. 实现 strStr()
 * link: https://leetcode-cn.com/problems/implement-strstr/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

// 暴力匹配、Knuth-Morris-Pratt 算法、Boyer-Moore 算法、Sunday 算法

// 暴力匹配
int strStr(char * haystack, char * needle){
    int nedLen = 0;

    if ((haystack == NULL) || (needle == NULL) || (strlen(needle) == 0)) {
        return 0;
    }

    nedLen = (int)strlen(needle);
    if (strlen(haystack) < nedLen) {
        return -1;
    }

    if (0 == strncmp(haystack,needle,nedLen)) {
        return 0;
    }

    for (int loop = 0; loop < (int)strlen(haystack); loop++) {
        if (haystack[loop] != needle[0]) {
            continue;
        }

        if (0 == strncmp(&haystack[loop],needle,strlen(needle))) {
            return loop;
        }
    }

    return -1;
}

// Knuth-Morris-Pratt 算法
int strStrKnuthMorrisPratt(char * haystack, char * needle){

}