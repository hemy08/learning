/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 88. 合并两个有序数组
 * link: https://leetcode-cn.com/problems/merge-sorted-array/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

void mergeTwoSortArrays(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    if ((nums2 == NULL) || (nums2 == NULL)) {
        return;
    }

    if (nums1Size < (m + n)) {
        return;
    }

    for (int i = 0; (i < (nums1Size - m)) && (i < n); i++) {
        nums1[i + m] = nums2[i];
    }

    qsort(nums1, nums1Size, sizeof(int), QsortCmpArrayAscOrder);
}