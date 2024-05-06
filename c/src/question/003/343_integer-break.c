/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 343. 整数拆分
 * link: https://leetcode-cn.com/problems/integer-break/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/7/30.
 */

#include "public.h"

/*
 * 动态规划，dp[n] 与 dp[i]、dp[n -i]有关
 */
int integerBreak(int n)
{
    int dp[100] = {0};
    for (int i = 2; i <= n; i++) {
        int result = 0;
        for (int j = 1; j < i; j++) {
            int tmp = j * GetMaxValue((i - j), dp[i - j]);
            result = GetMaxValue(tmp, result);
        }
        dp[i] = result;
    }

    return dp[n];
}


/*
 * 递归，因为有大量的重复计算，所以会超时， 这个最大只能计算到31
 */

int integerBreak2(int n)
{
    if (n <= 2) {
        return 1;
    }

    int tmp = 0;
    int result = 0;
    for (int i = 2; i < n;i++) {
        tmp = GetMaxValue((n - i), integerBreak(n - i));
        result = GetMaxValue(i * tmp, result);
    }

    return result;
}


/*
 * 递归，因为有大量的重复计算，使用全局变量记录重复的值，减少for循环计算
 */
#define MAX_VAL(a,b) ((a) > (b) ? (a) : (b))
int gResult[100] = {0};

int integerBreak3(int n)
{
    if (n <= 2) {
        return 1;
    }

    if (gResult[n] != 0) {
        return gResult[n];
    }

    int tmp = 0;
    int result = 0;
    for (int i = 2; i < n;i++) {
        tmp = GetMaxValue((n - i), integerBreak(n - i));
        result = GetMaxValue(i * tmp, result);
    }

    gResult[n] = result;
    return result;
}