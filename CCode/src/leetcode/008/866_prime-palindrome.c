/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved. 
 * Description: 866. 回文素数
 * link: https://leetcode-cn.com/problems/prime-palindrome/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

int g_fondflag = 0;

int isPrime(int x)
{
    if( x <= 1)
        return 0;
    for(int i = 2; (i * i) <= x; i++)
        if((x % i) ==0)
            return 0;
    return 1;
}

int covertStringToInteger(const char *acBuf, int maxLen)
{
    int out = 0;
    int cnt = 1;
    for (int i = (int)strlen(acBuf); i >= 0; i--) {
        if (acBuf[i] == '\0'){
            continue;
        }
        out += (acBuf[i] - 0x30)*cnt;
        cnt *= 10;
    }

    return out;
}

// 从左右两端向里面构建长度为 len+1 的回文数
void makePalindrome(const int N, char *str, const int len, int l, int r)
{
    if(g_fondflag) {
        return;
    }

    if (l > r) { // 构建完回文数，判断是不是素数
        int m = covertStringToInteger(str,12);
        g_fondflag = (m >= N) && isPrime(m);
        return;
    }

    for(int i = 0; i < 10; i++) {// 每一位从0到9遍历
        if(g_fondflag)
            return;
        if ((r==len) && (((i % 2) ==0)||(i==5))) { // 个位是2的倍数或者5肯定不是素数
            continue;
        }
        str[l] = (char)('0' + i);
        str[r] = (char)('0' + i);
        makePalindrome(N, str, len, l+1, r-1); // 从外到内，从小到大构建回文数
    }
}

int primePalindrome(int N)
{

    char str[12] = {0};
    int m=N, l=0;

    for(int i = N; i <= 11; i++)//小于10直接判断；11 要单独判断，因为偶数长度的回文数，奇数位上数字之和=偶数位上数字之和，是11的倍数，所以不是素数
        if(isPrime(i))
            return i;

    // 构建回文数进行判断
    // 构建回文数可以从 N 的当前长度开始：比如 N=123, 可以从长度为 3 的 101 开始构建。
    // 构建回文数可以忽略偶数长度，因为偶数长度的回文数，奇数位上数字之和=偶数位上数字之和，是11的倍数，所以不是素数。
    // 构建回文数可以从外到内，从小到大构建，这样可以保证结果递增。从外到内递归实现。
    // 最外层数字肯定不是 0, 因为最高位不是 0 ; 如果个位的数字是 2 的倍数或者是 5, 那肯定不是素数，可以忽略。

    g_fondflag = 0;
    while(m) {//找到N的长度
        m /= 10;
        l++;
    }

    for(int i = l/2; i < 5; i++) {//从N的长度的一半开始构建回文数，长度最多是9，因为题目说答案小于 2 * 10^8
        //str(i*2+1,'0');//奇数长度，l*2+1 ~ 9
        makePalindrome(N, str, i * 2, 0, i * 2);
        if(g_fondflag)
            return covertStringToInteger(str,12);
    }

    return -1;
}

