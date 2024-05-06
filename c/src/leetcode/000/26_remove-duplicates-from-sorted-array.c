/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 26. 删除排序数组中的重复项
 * link: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

// 数组动作
int removeDuplicates(int* nums, int numsSize)
{
    int count = 0;
    int i = 0;

    if (numsSize <= 1)  {
        return numsSize;
    }

    // 因为不需要考虑数组中超出新长度后面的元素，所以这里这里找到后面不同的，直接进行赋值。
    for (i = 1; i < numsSize; i++) {
        if (nums[count] != nums[i]) {
            count ++;
            nums[count] = nums[i];
        }
    }

    // 数组元素个数是下标+1
    count++;
    return count;
}

// 双指针
int removeDuplicates_doublePoint(int* nums, int numsSize)
{
    int begin = 0;
    int end = 0;

    if (numsSize <= 1)  {
        return numsSize;
    }

    // 因为不需要考虑数组中超出新长度后面的元素，所以这里这里找到后面不同的，直接进行赋值。
    for (end = 1; end < numsSize; end++) {
        if (nums[begin] != nums[end]) {
            begin ++;
            nums[begin] = nums[end];
        }
    }

    // 数组元素个数是下标+1
    begin++;
    return begin;
}