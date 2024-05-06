/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 1471. 数组中的 k 个最强值
 * link: https://leetcode-cn.com/problems/the-k-strongest-values-in-an-array/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */
#include "public.h"
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int g_midle = 0;

int compForStrongEstVal1(const void *a, const void* b)
{
    if (*(int*)a > *(int*)b) {
        return 1;
    }

    if (*(int*)a == *(int*)b) {
        return 0;
    }

    return -1;
}

int compForStrongEstVal2(const void *a, const void* b)
{
    if (abs(*(int*)a - g_midle) > abs(*(int*)b - g_midle)) {
        return 0;
    }

    if (abs(*(int*)a - g_midle) == abs(*(int*)b - g_midle)) {
        if (*(int*)a > *(int*)a) {
            return 0;
        }
    }

    return 1;
}
/*
void Sort(int* arr, int arrSize, int m)
{
    int pos = 0;
    int tmp = 0;
    for (int i = 0; i < arrSize; i++) {
        pos = i;
        for (int j = i; j < arrSize; j++) {
            if (abs(arr[pos] - m) > abs(arr[j] - m)) {
                continue;
            }

            if (abs(arr[pos] - m) == abs(arr[j] - m)) {
                if (arr[pos] > arr[j]) {
                    continue;
                }
            }

            pos = j;
        }

        tmp = arr[pos];
        arr[pos] = arr[i];
        arr[i] = tmp;
    }
}*/

int* getStrongest(int* arr, int arrSize, int k, int* returnSize)
{
    int m = (arrSize - 1) / 2;

    qsort(arr, arrSize, sizeof(int), compForStrongEstVal1);
    // Sort(arr, arrSize, arr[m]);
    g_midle = arr[m];
    qsort(arr, arrSize, sizeof(int), compForStrongEstVal2);
    *returnSize = k;
    return arr;
}