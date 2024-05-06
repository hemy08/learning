/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 53. 最大子序和
 * link: https://leetcode-cn.com/problems/maximum-subarray/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

#define MAX_VAL(a,b) ((a) > (b) ? (a) : (b))

int maxSubArray(int* nums, int numsSize)
{
    int num = INT_MIN;
    int fn = 0;
    for (int i = 0;i < numsSize; i++) {
        fn = GetMaxValue(nums[i], fn + nums[i]);
        num = GetMaxValue(fn, num);
    }

    return num;
}