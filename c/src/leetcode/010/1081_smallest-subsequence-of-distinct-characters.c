/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 1081. 不同字符的最小子序列
 * link:https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

#define MAX_CHAR_COUNT 26
int countCharNumbers(int *arr, int arrLen, const char *s)
{
    int len = strlen(s);
    int i = 0;
    // 因为仅包含小写字母，所以0 <= s[i] - 'a' <= 26
    for (i = 0; i < len; i++) {
        if ((s[i] > 'z') || (s[i] < 'a') || ((s[i] - 'a') >= arrLen)){
            return -1;
        }
        arr[s[i] - 'a']++;
    }

    return 0;
}

char *smallestSubsequence(char *s)
{
    unsigned int len = strlen(s);
    char *stack = NULL;
    int count[MAX_CHAR_COUNT] = {0}; // 记录每个字符出现的次数
    int stack_count[MAX_CHAR_COUNT] = {0}; // 栈里面字符出现的次数，最大只能是1
    int top = -1;
    int pos = 0;
    char c = '\0';

    // 因为仅包含小写字母，所以0 <= s[i] - 'a' <= 26
    if (countCharNumbers(count, MAX_CHAR_COUNT, s) != 0) {
        return NULL;
    }

    stack = (char*)malloc(sizeof(char) * (len + 1));
    if (stack == NULL) {
        return NULL;
    }
    (void)memset(stack, 0, (len + 1));

    while (s[pos] != '\0') {
        c = s[pos];
        // 当前元素已经在栈里面，不能入栈
        if (stack_count[c - 'a'] != 0) {
            count[c - 'a']--;
            pos++;
            continue;
        }

        // 栈里面有元素，当前元素不在栈里面，栈顶元素比当前元素大，并且栈顶元素后面还有，栈顶元素出栈, 直到栈顶元素唯一或者比当前元素小
        while ((top != -1) && (stack[top] > c) && (count[stack[top] - 'a'] != 0)) {
            stack_count[stack[top] - 'a']--;
            stack[top] = '\0';
            top--;
        }

        // 栈里面没有元素，或者已经出过栈，当前新元素入栈
        top++;
        stack[top] = c;
        stack_count[stack[top] - 'a']++;
        pos++;
        count[c - 'a']--;
    }

    return stack;
}