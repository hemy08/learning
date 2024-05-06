/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 1480. 一维数组的动态和
 * link: https://leetcode-cn.com/problems/running-sum-of-1d-array/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/6/15.
 */
#include "public.h"

int* runningSum(int* nums, int numsSize, int* returnSize){
    if ((nums == NULL) || (numsSize == 0)) {
        *returnSize = 0;
        return NULL;
    }

    int *dp = (int*)malloc(sizeof(int) * (numsSize + 1));

    dp[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        dp[i] = dp[i - 1] + nums[i];
    }

    *returnSize = numsSize;
    return dp;
}