/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 58. 最后一个单词的长度
 * link: https://leetcode-cn.com/problems/length-of-last-word/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

int lengthOfLastWord(char * s)
{
    size_t len = 0;
    int count = 0;

    if (s == NULL) return 0;
    
    len = strlen(s);
    if (len == 0) return 0;

    char *pEnd = s + len - 1;
    // 跳过最后的空格
    while (*pEnd == ' ') {
        // 只有空格
        if (pEnd == s) return 0;
        pEnd--;
    }

    // 跳过前面的空格
    while (*s == ' ') {
        // 只有空格
        if (pEnd == s) return 0;
        s++;
    }

    // 从后往前计数
    while (pEnd != s) {
        if (*pEnd == ' ') {
            return count;
        }
        count++;
        pEnd--;
    }
    
    // 只有一个字符串，没有空格
    return count + 1;
}