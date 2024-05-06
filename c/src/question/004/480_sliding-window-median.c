/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 480. 滑动窗口中位数
 * link: https://leetcode-cn.com/problems/sliding-window-median/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/8/17.
 */

#include "public.h"
#define MAX_NUMS_LEN 100000

int compMedianSlidingWindow(const void *a, const void *b)
{
    if (*(int*)a > *(int*)b) {
        return 1;
    }

    return -1;
}

double getMedianNum(const int* nums, int k)
{
    int mid = 0;
    double ans = 0;

    // k为奇数，取k-1/2位置的值
    if ((k % 2) == 1) {
        mid = (k - 1) / 2;
        ans = nums[mid];
    } else {
        // k 为偶数，取k/2 -1 和k/2的值求平均
        mid = k / 2;
        ans = (nums[mid - 1] / 2.0) + (nums[mid] / 2.0);
    }

    return ans;
}

int findKeyOutPos(const int* nums, int key, int low, int high)
{
    int mid = 0;

    if (nums[low] == key) {
        return low;
    }

    if (nums[high] == key) {
        return high;
    }

    mid = (low + high) / 2;
    if (nums[mid] > key) {
        return findKeyOutPos(nums, key, mid, high - 1);
    } else {
        return findKeyOutPos(nums, key, low + 1, mid);
    }
}

int findKeyInPos(int* nums, int numsSize, int key, int low, int high)
{
    int mid = 0;
    mid = (low + high) / 2;
    if (nums[mid] >= key) {
        // 到0了；
        if (mid < 1) {
            return mid;
        }
        if (nums[mid - 1] <= key) {
            // 插入到mid位置，mid的数据后移
            return mid;
        }
        return findKeyInPos(nums, numsSize, key, low, mid - 1);
    } else {
        // 到最大了
        if (mid + 1 >= numsSize) {
            return mid + 1;
        }

        if (nums[mid + 1] >= key) {
            // 插入到mid + 1位置，mid的数据后移
            return mid + 1;
        }
        return findKeyInPos(nums, numsSize, key, mid + 1, high);
    }
}

void slidingWindowOut(int* nums, int numsSize, int num)
{
    int winOut, i;
    winOut = findKeyOutPos(nums, num, 0, numsSize - 1);
    for (i = winOut + 1; i < numsSize; i++) {
        nums[i - 1] = nums[i];
    }
}

void slidingWindowIn(int* nums, int numsSize, int num)
{
    int winIn, i, pre, tmp;
    // 已经出去了一个值，这里nums就只有numsSize - 1个值了，数组还是有numsSize大小
    winIn = findKeyInPos(nums, numsSize - 1, num, 0, numsSize - 2);
    pre = nums[winIn];
    nums[winIn] = num;
    for (i = winIn + 1; i < numsSize; i++) {
        tmp = nums[i];
        nums[i] = pre;
        pre = tmp;
    }
}

double* medianSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    double *result = NULL;
    int i;
    int tmp[MAX_NUMS_LEN] = {0};

    if (k == 1) {
        result = (double*)malloc(sizeof(double) * numsSize);
        (void)memset(result, 0, sizeof(double) * numsSize);
        *returnSize = numsSize;
        for (i = 0; i < *returnSize; i++) {
            result[i] = nums[i];
        }
        return result;
    }
    // 只有一个滑动窗口
    if (numsSize <= k) {
        result = (double*)malloc(sizeof(double) * 2);
        (void)memset(result, 0, sizeof(double) * 2);
        *returnSize = 1;
        qsort(nums, numsSize, sizeof(int), compMedianSlidingWindow);
        result[0] = getMedianNum(nums, k);
        return result;
    }

    // 多个滑动窗口
    result = (double*)malloc(sizeof(double) * MAX_NUMS_LEN);
    (void)memset(result, 0, sizeof(double) * MAX_NUMS_LEN);
    memcpy(tmp, nums, k * sizeof(int));
    qsort(tmp, k, sizeof(int), compMedianSlidingWindow);
    result[0] = getMedianNum(tmp, k);
    *returnSize = numsSize - k + 1;
    for (i = 1; i < *returnSize; i++) {
        slidingWindowOut(tmp, k, nums[i - 1]);
        slidingWindowIn(tmp, k, nums[i + k - 1]);
        result[i] =  getMedianNum(tmp, k);
    }

    return result;
}

/*
int main()
{
    int nums[] = {1,3,-1,-3,5,3,6,7};
    int resultlen = 0;
    double *result = NULL;
    result = medianSlidingWindow(nums, 8, 3, &resultlen);

    for (int i = 0; i < resultlen; i++) {
        printf("%f ", result[i]);
    }
}*/
