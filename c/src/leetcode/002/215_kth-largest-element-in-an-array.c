/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 215. 数组中的第K个最大元素
 * link: https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/11/9.
 */

#include "public.h"

int findKthLargest(int* nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), QsortCmpArrayAscOrder);
    if (k > numsSize) {
        return 0;
    }
    return nums[numsSize - k];
}