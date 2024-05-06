/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 81. 搜索旋转排序数组 II
 * link: https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

int recurBinary(int *a, int key, int low, int high)
{
    int mid;
    if(low > high) {
        return -1;
    }

    mid = low + (high - low) / 2;
    // printf("low %d high %d, a[mid] %d\n", low, high, a[mid]);
    if(a[mid] == key) {
        return mid;
    } else if (a[mid] > key) {
        return recurBinary(a, key, low, mid - 1);
    } else {
        return recurBinary(a, key, mid + 1, high);
    }
}

bool searchRotatedII(int* nums, int numsSize, int target){
    int point = 0;
    int find = -1;

    if (numsSize == 0) {
        return false;
    }

    if (nums[0] == target) {
        return true;
    }

    // 找到旋转点，nums[i] > nums[i+1]
    for (point = 0; point < (numsSize - 1); point++) {
        if (nums[point] > nums[point + 1]) {
            break;
        }
    }

    // nums[point] 是最大值， nums[point + 1]是最小值
    // 因为是排好序的，所以nnums[0]是前面point中的最小值，并且>nums[numsSize - 1]
    if (target > nums[0]){
        find = dichotomySearch(nums, target, 0, point);
    } else {
        find = dichotomySearch(nums, target, point + 1, numsSize - 1);
    }

    return find == -1? false:true;
}