/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 34. 在排序数组中查找元素的第一个和最后一个位置
 * link: https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/12/1.
 */

#include "public.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int * result = (int *)malloc(sizeof(int) * 2);
    result[0] = -1;
    result[1] = -1;

    *returnSize = 2;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < target) {
            continue;
        }

        if (nums[i] != target) {
            return result;
        }

        if (result[0] == -1) {
            result[0] = i;
        }
        result[1] = i;
    }
    return result;
}*/

/*int* searchRange34(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *a = calloc(2, sizeof(int));
    int first = 0;
    int find = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] == target)
        {
            if(first == 0)
            {
                a[0] = i;
                first = 1;
            }
            else
            {
                a[1] = i;
            }
            find++;
        }
    }
    if(find == 0)
    {
        a[0] = -1;
        a[1] = -1;
    }
    else if(find == 1)
    {
        a[1] = a[0];
    }
    return a;
}*/

// 找左侧的边界
int binarySearchLeft(int *nums,int low, int high, int target)
{
    int mid = (low + high) / 2;

    if (nums[low] == target) {
        return low;
    }

    if (low > high) {
        return -1;
    }

    if (nums[mid] >= target) {
        return binarySearchLeft(nums, low, mid - 1, target);
    }
    return binarySearchLeft(nums, mid + 1, high, target);
}

int binarySearchRight(int *nums,int low, int high, int target)
{
    int mid = (low + high) / 2;

    if (nums[high] == target) {
        return high;
    }

    if (low > high) {
        return -1;
    }

    if (nums[mid] > target) {
        return binarySearchRight(nums, low, mid - 1, target);
    }
    return binarySearchRight(nums, mid + 1, high, target);
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *result = (int *) malloc(sizeof(int) * 2);
    *returnSize = 2;
    result[0] = -1;
    result[1] = -1;
    // 为空，或者target在数组区间外
    if ((numsSize == 0) || (nums[0] > target) || (nums[numsSize - 1] < target)){
        return result;
    }

    result[0] = binarySearchLeft(nums, 0, numsSize - 1, target);
    result[1] = binarySearchRight(nums, 0, numsSize - 1, target);
    return result;
}