/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 697. 数组的度
 * link: https://leetcode-cn.com/problems/degree-of-an-array/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/8/6.
 */

#include "public.h"

#define MAX_NUMS_LEN 50000

int findShortestSubArray(int* nums, int numsSize)
{
    int dp[MAX_NUMS_LEN], start[MAX_NUMS_LEN], result[MAX_NUMS_LEN];
    int max = 0;
    int min = MAX_NUMS_LEN;

    memset(dp, 0, sizeof(dp));
    memset(start, -1, sizeof(dp));
    memset(result, 0, sizeof(dp));

    // 计数，找到数组的度，同时记录起始位置，标记出现的值
    for (int i = 0; i < numsSize; i++) {
        int key = nums[i];
        dp[key]++;
        // 直接计算度
        if (max < dp[key]) {
            max = dp[key];
        }

        //记录起始位置
        if (start[key] < 0) {
            start[key] = i;
        }

        // 直接计算当前数字距离上一次出现时的距离
        result[key] = i - start[key] + 1;
    }

    // 计算最小值
    for (int i = 0; i < numsSize; i++) {
        int key = nums[i];
        // 找到度，最先出现的位置
        if (dp[key] != max) {
            continue;
        }

        // 计算子数组长度的最小值
        min = MIN_VAL(min,  result[key]);
    }

    return min;
}
