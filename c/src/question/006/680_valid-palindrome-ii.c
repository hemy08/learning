/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 680. 验证回文字符串 Ⅱ
 * link: https://leetcode-cn.com/problems/valid-palindrome-ii/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/8/5.
 */

#include "public.h"

bool checkSubStrPalindromeII(const char *start, const char *end, int flag)
{
    // printf("start %c, end %c, flag %d\n", *start, *end, flag);
    // 地址相同
    if (start >= end) {
        return true;
    }

    // 值相同
    if (*start == *end) {
        return checkSubStrPalindromeII(start + 1, end - 1, flag);
    }

    if (flag == 1) {
        return false;
    }

    // 删除start比较
    if (checkSubStrPalindromeII(start + 1, end, 1)) {
        return true;
    }

    // 删除end比较
    if (checkSubStrPalindromeII(start, end - 1, 1)) {
        return true;
    }

    return false;
}

bool validPalindrome(char * s)
{
    char* end = s + (int)strlen(s) - 1;
    return checkSubStrPalindromeII(s, end, 0);
}