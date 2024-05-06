/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 746. 使用最小花费爬楼梯
 * link: https://leetcode-cn.com/problems/min-cost-climbing-stairs/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

int minCostClimbingStairs(int* cost, int costSize)
{
    if (costSize == 0) {
        return 0;
    }

    if (costSize == 1) {
        return cost[0];
    }

    int dpi_1 = cost[0];
    int dpi_2 = 0;
    int dp = 0;
    for (int i = 1; i < costSize; ++i) {
        dp = cost[i] + GetMinValue(dpi_1, dpi_2);
        dpi_2 = dpi_1;
        dpi_1 = dp;
    }

    return GetMinValue(dpi_1,dpi_2);
}

/*
 * 动态规划+贪心思想
 * dp[i] = cost[i] + MIN_VAL(dp[i - 1], dp[i - 2])
 * 优化代码，dp[i - 1], dp[i - 2]只有在计算dp[i]的时候才用到，可以使用局部变量代替，然后每次dp值计算完之后，两个值后移就可以
 * min_stair = MIN_VAL(dp_1, dp_2);
 * dp = min_stair + cost[i];
 * dp_2 = dp_1;
 * dp_1 = dp;
 * */
int minCostClimbingStairs2(int* cost, int costSize)
{
    int dp[1000];

    memset(dp, 0, sizeof(dp));

    // 只有一个阶梯
    if (costSize == 1) {
        return cost[0];
    }

    // 有俩阶梯
    if (costSize == 2) {
        return GetMinValue(cost[0], cost[1]);
    }

    // 从0开始
    dp[0] = cost[0];
    dp[1] = cost[1];
    int min_stair = 0;
    for(int i = 2; i < costSize; i++) {
        min_stair = GetMinValue(dp[i - 1], dp[i - 2]);
        dp[i] = min_stair + cost[i];
    }

    min_stair = GetMinValue(dp[costSize - 1], dp[costSize - 2]);

    return min_stair;
}