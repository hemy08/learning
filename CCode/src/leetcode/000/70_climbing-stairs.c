/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 70. 爬楼梯
 * link: https://leetcode-cn.com/problems/climbing-stairs/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

int funcFibonacciDp(int n, int dp[], int max)
{
    // 出错了，数组不够大了
    if (n > max) {
        return 0;
    }

    // n的值已经有了
    if (dp[n] != 0) {
        return dp[n];
    }

    // n - 1 不为0 的时候，n - 2必然不为0，这里就不做判断
    if (dp[n - 1] != 0) {
        dp[n] = dp[n - 1] + dp[n - 2];
    } else if (dp[n - 2] != 0) { // n - 1为0，n -2不为0，需要先计算n-1的值
        dp[n] = funcFibonacciDp(n - 1, dp, max) + dp[n - 2];
    } else  { // n - 1和n - 2 都为0，需要继续往下计算其值。
        dp[n] = funcFibonacciDp(n - 1, dp, max) + funcFibonacciDp(n - 2, dp, max);
    }
    return dp[n];
}

int climbStairs(int n)
{
    int *dp = NULL;

    if (n <= 2) {
        return n;
    }

    dp = (int*)malloc((n + 1) * sizeof(int));
    memset(dp, 0, (n + 1) * sizeof(int));
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    return funcFibonacciDp(n,dp,n + 1);
}