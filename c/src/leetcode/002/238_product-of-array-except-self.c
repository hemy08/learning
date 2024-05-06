/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 238. 除自身以外数组的乘积
 * link: https://leetcode-cn.com/problems/product-of-array-except-self/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */
#include "public.h"

// 从前往后，每个nums[i]的值为nums[0] * nums[1] * ..... * nums[i]
int *getMultiUp(int* nums, int numsSize)
{
    int i = 0;
    int *result = NULL;

    if ((nums == NULL) || (numsSize == 0)) {
        return NULL;
    }

    result = (int *)malloc(sizeof(int) * (numsSize + 1));
    if (result == NULL) {
        return NULL;
    }
    result[0] = nums[0];

    for (i = 1; i < numsSize; i++) {
        result[i] = result[i - 1] * nums[i];
    }

    return result;
}

// 从后往前，每个nums[i]的值为nums[i] * nums[i + 1] * ..... * nums[numsSize - 1]
int *getMultiDown(int* nums, int numsSize)
{
    int i = 0;
    int *result = NULL;

    if ((nums == NULL) || (numsSize == 0)) {
        return NULL;
    }

    result = (int *)malloc(sizeof(int) * (numsSize + 1));
    if (result == NULL) {
        return NULL;
    }
    result[numsSize - 1] = nums[numsSize -1];

    for (i = numsSize - 2; i >= 0; i--) {
        result[i] = result[i + 1] * nums[i];
    }

    return result;
}

int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    int i = 0;
    int *resultUp = NULL;
    int *resultDown = NULL;

    if ((nums == NULL) || (numsSize == 0)) {
        *returnSize = 0;
        return NULL;
    }

    // 从前往后，每个nums[i]的值为nums[0] * nums[1] * ..... * nums[i]
    resultUp = getMultiUp(nums, numsSize);
    // 从后往前，每个nums[i]的值为nums[i] * nums[i + 1] * ..... * nums[numsSize - 1]
    resultDown = getMultiDown(nums, numsSize);
    if ((resultUp == NULL) || (resultDown == NULL)) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = numsSize;
    // nums[i]的值为nums[0] * nums[1] * ..... * nums[i - 1] * nums[i + 1] * ..... * nums[numsSize - 1]
    // 就是resA[i - 1] * resB[i + 1]
    nums[0] = resultDown[1];
    nums[numsSize - 1] = resultUp[numsSize - 2];
    for (i = 1; i < numsSize - 1; i++) {
        nums[i] = resultUp[i - 1] * resultDown[i + 1];
    }

    return nums;
}