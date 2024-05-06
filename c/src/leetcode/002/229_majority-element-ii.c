/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 229. 求众数 II
 * link: https://leetcode-cn.com/problems/majority-element-ii/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/8/5.
 */
#include "public.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compForMajorityElement(const void*a, const void*b)
{
    if (*(int*)a >= *(int*)b) {
        return 1;
    }

    return -1;
}
int* majorityElement(int* nums, int numsSize, int* returnSize)
{
    int min_times = numsSize / 3;
    if ((nums == NULL) || (numsSize == 0)) {
        *returnSize = 0;
        return NULL;
    }

    // 先排序
    qsort(nums, numsSize, sizeof(int), compForMajorityElement);

    int key = nums[0];
    int times = 1;
    int count = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == key) {
            times++;
            continue;
        }

        // 超过最小次数，记录下来
        if (times > min_times) {
            nums[count] = key;
            count++;
        }

        // 下一个值的重复
        key = nums[i];
        times = 1;
    }

    // 超过最小次数，记录下来
    if (times > min_times) {
        nums[count] = key;
        count++;
    }

    *returnSize = count;
    return nums;
}