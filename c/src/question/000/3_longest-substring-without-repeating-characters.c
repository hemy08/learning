/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 3. 无重复字符的最长子串
 * link: https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

#define MAX_CHAR_NUM 128
#define MAX_STR_LEN 1024

int lengthOfLongestSubstring(char *s)
{
    int len = strlen(s);
    char *stack;
    int stack_count[MAX_CHAR_NUM] = {0}; // 存储无重复字符的子串中字符出现次数
    int pos = 0;
    int start = 0;
    int count = 0;
    int max = 0;

    if (s == NULL) {
        return 0;
    }

    if (len <= 1) {
        return len;
    }

    stack = (char*)malloc(sizeof(char) * (len + 1));

    while (s[pos] != '\0') {
        // t不在栈里面，入栈
        if (stack_count[s[pos]] > start) {
            // 在栈里面，计算长度， 当前位置 - 之前存在的位置
            count = pos - start;
            max = max > count ? max : count;

            // 新的子串从上一个重复字符之后计算
            start = stack_count[s[pos]];
        }
        stack_count[s[pos]] = pos + 1; //记录新位置
        pos++;
    }
    // z最后一次的长度
    count = pos - start;

    return max > count ? max : count;
}