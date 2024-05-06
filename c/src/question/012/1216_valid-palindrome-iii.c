/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 1216. 验证回文字符串 III
 * link: https://leetcode-cn.com/problems/valid-palindrome-iii/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/8/5.
 */

#include "public.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * 递归处理，超时了，通过了44个用例
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ** * * * * * * * */
bool checkSubStrPalindromeIII(const char *start, const char *end, int flag)
{
    // while循环先检查一遍，找到下一个不等的地方
    while (start < end) {
        if (*start != *end) {
            break;
        }
        start++;
        end--;
    }

    // 地址相同
    if (start >= end) {
        return true;
    }

    if (flag <= 0) {
        return false;
    }

    // 删除start比较
    if (checkSubStrPalindromeIII(start + 1, end, flag - 1)) {
        return true;
    }

    // 删除end比较
    if (checkSubStrPalindromeIII(start, end - 1, flag - 1)) {
        return true;
    }

    return false;
}

bool isValidPalindrome(char * s, int k)
{
    char* end = s + (int)strlen(s) - 1;
    return checkSubStrPalindromeIII(s, end, k);
}