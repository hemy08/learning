/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 162. 寻找峰值
 * link: https://leetcode-cn.com/problems/find-peak-element/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/12/3.
 */

#include "public.h"

int findPeakElement(int* nums, int numsSize)
{
    int *stack = (int*)malloc(sizeof(int) * numsSize);
    (void)memcpy(stack, nums, sizeof(int) * numsSize);
    qsort(stack, numsSize, sizeof(int), QsortCmpArrayDescOrder);
    int max = stack[0];
    free(stack);
    //int *result = (int*)bsearch(&stack[0], nums, numsSize, sizeof(int), compare162Descending);

    for (int i = 0; i < numsSize; i++) {
        if (max == nums[i]) {
            return i;
        }
    }
    return 0;
}