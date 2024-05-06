/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description:41. 缺失的第一个正数
 * link:https://leetcode-cn.com/problems/first-missing-positive/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/12/4.
 */

#include "public.h"

int compIntegerNumber(const void *a, const void *b)
{
    if (*(int*)a > *(int*)b) {
        return 1;
    }

    return -1;
}
int firstMissingPositive(int* nums, int numsSize)
{
    // 从小到大排序
    qsort(nums, numsSize, sizeof(int), compIntegerNumber);

    // 从头往后找
    int number = 1;
    for (int i = 1; i < numsSize; i++) {
        // 小于1的值不考虑
        if (nums[i] < number) {
            continue;
        }

        // 等于number的时候，number++
        if (nums[i] == number) {
            number++;
        } else {
            return number;
        }
    }

    return number;
}

int firstMissingPositiveBSearch(int* nums, int numsSize)
{
    // 从小到大排序
    qsort(nums, numsSize, sizeof(int), compIntegerNumber);

    // 从头往后找
    int number = 1;
    for (int i = 1; i < numsSize; i++) {
        // 小于1的值不考虑
        if (nums[i] < number) {
            continue;
        }

        // 等于number的时候，number++
        if (nums[i] == number) {
            number++;
        } else {
            return number;
        }
    }

    return number;
}

int firstMissingPositiveSolution2(int* nums, int numsSize)
{
    // 将所有的数都变成正数
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= 0) {
            nums[i] = numsSize + 1;
        }
    }

    // 对于所有的正数，x = nums[i] 应该出现在 x位置上，交换nums[x]的值和nums[i]的值
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if (num <= numsSize) {
            nums[num] = num;
        }
    }

    // 判断nums[i]是不是等于i，如果不等，则返回i + 1,从1开始
    // 上一步结束后，数组相当于从小到大排序，中间穿插一部分值为numsSize+1；我们只需要关注排序的部分是不是在自己的位置上。
    for (int i = 1; i < numsSize; i++) {
        // 排除最大的
        if (nums[i] > numsSize) {
            continue;
        }

        // 满足条件的应该是nums[i] = i；
        if (nums[i] > i) {
            return i;
        }
    }
    return numsSize + 1;
}
