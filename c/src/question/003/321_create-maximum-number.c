/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 321. 拼接最大数
 * link: https://leetcode-cn.com/problems/create-maximum-number/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/12/2.
 */

#include "public.h"

int compareTwoSeq(int* subseq1, int subseq1Size, int index1, int* subseq2, int subseq2Size, int index2) {
    while (index1 < subseq1Size && index2 < subseq2Size) {
        int difference = subseq1[index1] - subseq2[index2];
        if (difference != 0) {
            return difference;
        }
        index1++;
        index2++;
    }
    return (subseq1Size - index1) - (subseq2Size - index2);
}

int* mergeTwoSeq(int* subseq1, int subseq1Size, int* subseq2, int subseq2Size) {
    if (subseq1Size == 0) {
        return subseq2;
    }
    if (subseq2Size == 0) {
        return subseq1;
    }
    int mergeLength = subseq1Size + subseq2Size;
    int* merged = malloc(sizeof(int) * (subseq1Size + subseq2Size));
    int index1 = 0, index2 = 0;
    for (int i = 0; i < mergeLength; i++) {
        if (compareTwoSeq(subseq1, subseq1Size, index1, subseq2, subseq2Size, index2) > 0) {
            merged[i] = subseq1[index1++];
        } else {
            merged[i] = subseq2[index2++];
        }
    }
    return merged;
}

int* MaxSubsequence(int* nums, int numsSize, int k) {
    int* stack = malloc(sizeof(int) * k);
    memset(stack, 0, sizeof(int) * k);
    int top = -1;
    int remain = numsSize - k;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        while (top >= 0 && stack[top] < num && remain > 0) {
            top--;
            remain--;
        }
        if (top < k - 1) {
            stack[++top] = num;
        } else {
            remain--;
        }
    }
    return stack;
}

void swapForMaxNumber(int** a, int** b) {
    int* tmp = *a;
    *a = *b, *b = tmp;
}

int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize) {
    int* maxSubsequence = malloc(sizeof(int) * k);
    memset(maxSubsequence, 0, sizeof(int) * k);
    *returnSize = k;
    int start = fmax(0, k - nums2Size), end = fmin(k, nums1Size);
    for (int i = start; i <= end; i++) {
        int* subseq1 = MaxSubsequence(nums1, nums1Size, i);
        int* subseq2 = MaxSubsequence(nums2, nums2Size, k - i);
        int* curMaxSubsequence = mergeTwoSeq(subseq1, i, subseq2, k - i);
        if (compareTwoSeq(curMaxSubsequence, k, 0, maxSubsequence, k, 0) > 0) {
            swapForMaxNumber(&curMaxSubsequence, &maxSubsequence);
        }
    }
    return maxSubsequence;
}


int* maxNumber2(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize) {
    int *result = (int*)malloc(sizeof(int) * k);
    memset(result, 0, sizeof(int) * k);
    *returnSize = k;

    // 刚好合并
    if ((nums1Size + nums2Size) == k) {
        return mergeTwoSeq(nums1, nums1Size, nums2, nums2Size);
    }

    // 取nums1Size、nums2Size、k三个数中最小数作为结束
    int num = nums1Size > nums2Size ? nums2Size : nums1Size;
    num = num > k ? k : num;
    for (int i = 0; i < num; i++) {
        int *sub1;
        int *sub2;
        // nums1最后可能全取完
        if (nums1Size < nums2Size) {
            sub1 = MaxSubsequence(nums1, nums1Size, i);
            sub2 = MaxSubsequence(nums2, nums2Size, k - i);
        } else {// nums2最后可能全取完
            sub1 = MaxSubsequence(nums2, nums2Size, i);
            sub2 = MaxSubsequence(nums1, nums1Size, k - i);
        }

        // 合并两个数组
        int* curMaxSub = mergeTwoSeq(sub1, i, sub2, k - i);

        // 比较数组，然后交换
        if (compareTwoSeq(curMaxSub, k, 0, result, k, 0) > 0) {
            swapForMaxNumber(&curMaxSub, &result);
        }
    }

    return result;
}