/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 280. 摆动排序
 * link: https://leetcode-cn.com/problems/wiggle-sort/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

void swapWiggleSort(int *nums, int a, int b)
{
    int tmp = 0;
    tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}

void wiggleSort(int* nums, int numsSize)
{
    // 循环，不满足条件就交换
    for (int i = 0; i < (numsSize - 1); i++) {
        // 偶数
        if ((i % 2) == 0) {
            if (nums[i] > nums[i + 1]) {
                swapWiggleSort(nums, i, i + 1);
            }
        } else {
            if (nums[i] < nums[i + 1]) {
                swapWiggleSort(nums, i, i + 1);
            }
        }
    }
}