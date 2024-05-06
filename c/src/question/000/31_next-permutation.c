/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 31. 下一个排列
 * link: https://leetcode-cn.com/problems/next-permutation/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/11/10.
 */

#include "public.h"

int compareNextPermutation(void *a, void *b)
{
    return *(int*)a - *(int*)b;
}

void swapNumbers(int *a, int *b) {
    int t = *a;
    *a = *b, *b = t;
}

/*void nextPermutation(int* nums, int numsSize)
{
    if ((nums == NULL) || (numsSize < 2)) {
        return;
    }

    // 第一步，从后往前找第一个下降的点
    int i = numsSize - 2;
    while (i >= 0) {
        if (nums[i + 1] > nums[i]) {
            break;
        }
        i--;
    }

    if (i < 0) {
        // 整改序列是降序的，直接重排
        qsort(nums, numsSize, sizeof(int), compare);
        return;
    }

    int j = numsSize - 1;
    while (j >= 0) {
        if (nums[j] > nums[i]) {
            break;
        }
        j--;
    }

    swap(&nums[i], &nums[j]);

    // 对i之后的进行排序
    qsort(&nums[i], (numsSize - i), sizeof(int), compare);
}*/

int findLastPeakPos(int* nums, int numsSize)
{
    int cur = numsSize - 2;
    while (cur >= 0) {
        if (nums[cur + 1] > nums[cur]) {
            break;
        }
        cur--;
    }
    cur++;

    return cur;
}

int findSwapPos(int* nums, int numsSize, int pos)
{
    for (int i = pos; i < numsSize; i++) {
        if (nums[i] > nums[pos]) {
            return i;
        }
    }

    return -1;
}

void nextPermutation(int* nums, int numsSize)
{
    if ((nums == NULL) || (numsSize < 2)) {
        return;
    }

    int last_peak = findLastPeakPos(nums, numsSize);
    qsort(nums + last_peak, (numsSize - last_peak), sizeof(int), compareNextPermutation);
    if (last_peak < 1) {
        return;
    }

    int swap_pos = findSwapPos(nums, numsSize, last_peak);
    if (swap_pos < 0) {
        return;
    }

    swapNumbers(&nums[last_peak - 1], &nums[swap_pos]);
}