/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 265. 粉刷房子 II
 * link: https://leetcode-cn.com/problems/paint-house-ii/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/9/1.
 */

#include "public.h"

int getMinConstPosition(int *nums, int numsSize, int *pos)
{
    int min_pos = 0;
    int min = 99999;
    for (int i = 0; i < numsSize; i++) {
        if (i == *pos) {
            continue;
        }
        if (min > nums[i]) {
            min = nums[i];
            min_pos = i;
        }
    }

    *pos = min_pos;
    return min;
}

int minCostII(int** costs, int costsSize, int* costsColSize)
{
    int min = 0;
    int last = -1;
    int cur_min = 0;

    min = getMinConstPosition(costs[0], *costsColSize, &last);
    for (int i = 1; i < costsSize; i++) {
        cur_min = getMinConstPosition(costs[0], *costsColSize, &last);
        min += cur_min;
    }

    return min;
}