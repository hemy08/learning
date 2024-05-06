/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 256. 粉刷房子
 * link: https://leetcode-cn.com/problems/paint-house/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

// 不申请内存的方式，不使用临时变量的方式
int minCost(int** costs, int costsSize, int* costsColSize)
{
    if (costsSize == 0) {
        return 0;
    }

    for (size_t i = 1; i < costsSize; i++) {
        costs[i][0] += GetMinValue(costs[i - 1][1], costs[i - 1][2]);
        costs[i][1] += GetMinValue(costs[i - 1][0], costs[i - 1][2]);
        costs[i][2] += GetMinValue(costs[i - 1][0], costs[i - 1][1]);
    }
    
    return GetMinValue(GetMinValue(costs[costsSize - 1][0], costs[costsSize - 1][1]), costs[costsSize - 1][2]);
}

/*=================================方案二================================*/
int minCost2(int** costs, int costsSize, int* costsColSize)
{

    if (costsSize == 0) {
        return 0;
    }

    int dp_0 = costs[0][0];
    int dp_1 = costs[0][1];
    int dp_2 = costs[0][2];
    int tmp0 = 0, tmp1 = 0, tmp2 = 0;
    
    for (size_t i = 1; i < costsSize; i++) {
        tmp0 = costs[i][0] + GetMinValue(dp_1, dp_2);
        tmp1 = costs[i][1] + GetMinValue(dp_0, dp_2);
        tmp2  = costs[i][2] + GetMinValue(dp_0, dp_1);
        dp_0 = tmp0;
        dp_1 = tmp1;
        dp_2 = tmp2;
    }
    
    return GetMinValue(GetMinValue(dp_0, dp_1), dp_2);
}

/*=================================方案三================================*/
int minCost3(int** costs, int costsSize, int* costsColSize)
{
    int **dp = NULL;
    
    if (costsSize == 0) {
        return 0;
    }

    if (costsSize == 1) {
        return GetMinValue(GetMinValue(costs[0][0], costs[0][1]), costs[0][2]);
    }
    
    dp = (int**)malloc((costsSize + 1) * sizeof(int*));
    if (dp == NULL) {
        return 0;
    }

    for (size_t i = 0; i < costsSize; i++) {
        dp[i] = (int*)malloc(3 * sizeof(int));
    }
    
    dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    dp[0][2] = costs[0][2];
    for (size_t i = 1; i < costsSize; i++) {
        dp[i][0] = costs[i][0] + GetMinValue(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = costs[i][1] + GetMinValue(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = costs[i][2] + GetMinValue(dp[i - 1][0], dp[i - 1][1]);
    }
    
    return GetMinValue(GetMinValue(dp[costsSize - 1][0], dp[costsSize - 1][1]), dp[costsSize - 1][2]);
}