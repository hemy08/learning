/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 316. 去除重复字母
 * link: https://leetcode-cn.com/problems/remove-duplicate-letters/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

#define MAX_CHAR_COUNT  27

int getCharNumbers(int *arr, int arrLen, const char *s)
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

char *removeDuplicateLetters(char *s)
{
    unsigned int len = strlen(s);
    char *stack = NULL;
    int count[MAX_CHAR_COUNT] = {0}; // 记录每个字符出现的次数
    int stack_count[MAX_CHAR_COUNT] = {0}; // 栈里面字符出现的次数，最大只能是1
    int top = -1;
    int pos = 0;
    char c = '\0';

    // 因为仅包含小写字母，所以0 <= s[i] - 'a' <= 26
    if (getCharNumbers(count, MAX_CHAR_COUNT, s) != 0) {
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


#define MAX_NUMS 27

void countDuplicateLetters(char *s, int *nums, int numsSize)
{
    char *start = s;
    while (*start != '\0') {
        int index = *start - 'a';
        if (index >= numsSize) {
            return;
        }

        nums[index]++;
        start++;
    }
}

char* RemoveDuplicateLetters(char* s)
{
    int len;
    char *stack = NULL;
    char *cur = s;
    int stack_num = -1;
    int count[MAX_NUMS] = {0};
    int stack_count[MAX_NUMS] = {0};
    // 计数
    (void)memset(count , 0x00000000, sizeof(int) * MAX_NUMS);
    (void)memset(stack_count, 0x00000000, sizeof(int) * MAX_NUMS);
    countDuplicateLetters(s, count, MAX_NUMS - 1);

    len =  (int)strlen(s) + 1;
    stack = (char*)malloc(len * sizeof(char ));
    if (stack == NULL) {
        return NULL;
    }

    (void)memset(stack, '\0', len);
    while (*cur != '\0') {
        int index = *cur - 'a';
        // 已经在栈里，不入栈
        if (stack_count[index] != 0) {
            count[index]--;
            cur++;
            continue;
        }

        // 栈里面没有，入栈,当前元素比栈顶元素小，如果栈顶元素后面还有，栈顶元素需要出栈
        while ((stack_num != -1) && (stack[stack_num] > *cur) && (count[stack[stack_num] - 'a'] > 0)) {
            stack_count[stack[stack_num] - 'a']--;
            stack[stack_num] = '\0';
            stack_num--;
        }

        // 入栈
        stack_num++;
        stack[stack_num] = *cur;
        cur++;
        stack_count[index]++;
        count[index]--;
    }

    return stack;
}