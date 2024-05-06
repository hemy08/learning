/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 5. 最长回文子串
 * link: https://leetcode-cn.com/problems/longest-palindromic-substring/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

// gcc -g src/5_最长回文子串.c -L./lib -lsecurec -o leetcode.exe

#define GET_MAX_VAL(a, b) ((a) > (b) ? (a) : (b))

int findMaxSubStringLengthAroundCenter(char *s, int lenmax, int left, int right)
{
    int L = left, R = right;

    // right 超过数组最大下标了
    if (right >= lenmax) {
        return 1;
    }

    // 字符串相同的时候，地址进行编译，不相同的时候，
    while ((L >= 0) && (R < lenmax) && (s[L] == s[R])) {
        L--;
        R++;
    }
    // 左边界值在回文子串中, s[0] = s[R-1] 长度 (R - 1) - (L + 1) + 1;
    // 右边界值在回文子串中, s[L + 1] = s[lenmax - 1] 长度 lenmax - 1 - (L + 1) + 1;
    return R - L - 1;
}

char * longestPalindrome(char * s)
{
    int length;
    char* start = s;
    int lenget = 0;

    if ((s == NULL) || (strlen(s) < 1)) return "";

    length = strlen(s);
    // 超过2的时候，计算
    for (int i = 0; i < length; i++) {

        // 以i为中心计算最大回文串长度，start = s偏移 i - (len - 1 去掉i位置) / 2， 长度是奇数
        int len1 = findMaxSubStringLengthAroundCenter(s, length, i, i);
        // 以i，i+1之间为中心，计算最大回文串长度,start = s偏移 i - (len - 2，去掉i，i+1位置) / 2， 返回的是偶数
        int len2 = findMaxSubStringLengthAroundCenter(s, length, i, i + 1); 

        // 找到两种方式的最大值
        int len = GET_MAX_VAL(len1, len2);
        if (len > lenget) {
            lenget = len;
            // 进行地址偏移, i往前第（len - 1/2）
            start = s + i - (len - 1) / 2;
        }

        // printf("\nstart: %s, len = %d, len1 = %d, len2 = %d, i = %d", start, lenget, len1, len2, i);
    }

    // 地址最后的长度归零，如果是末尾，则不清理
    if (start + lenget < s + length) {
        start[lenget] = '\0';
    }
    return start;
}
/*

int main()
{
    char src[100] = "babad";
    char src1[100] = "a";
    char src2[100] = "aaa";
    char src3[100] = "aaaa";
    char src4[100] = "aaaad";
    char src5[100] = "abcde";
    printf("\nsrc: %s, result: %s", src, longestPalindrome(src));
    printf("\nsrc: %s, result: %s", src1, longestPalindrome(src1));
    printf("\nsrc: %s, result: %s", src2, longestPalindrome(src2));
    printf("\nsrc: %s, result: %s", src3, longestPalindrome(src3));
    printf("\nsrc: %s, result: %s", src4, longestPalindrome(src4));
    printf("\nsrc: %s, result: %s", src5, longestPalindrome(src5));
    return 0;
}*/
