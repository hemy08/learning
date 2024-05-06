/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 33. 搜索旋转排序数组
 * link: https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

int searchFuncOne(int* nums, int numsSize, int target)
{
    int x = 0;
    int y = numsSize;
    while(x < y){
        int m = x+(y-x)/2;
        if(nums[m] == target) return m;
        if(nums[m] <= nums[y-1]){//注意m可能等于y-1
            //右边是有序的
            if(nums[m] < target && target <= nums[y-1]) x=m+1;
            else y=m;
        }else{
            //左边是有序的
            if(nums[x] <= target && target < nums[m]) y=m;
            else x=m+1;
        }
    }
    return -1;
}

// 二分法查找
int dichotomySearch(int *a, int key, int low, int high)
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
        return dichotomySearch(a, key, low, mid -1);
    } else {
        return dichotomySearch(a, key, mid + 1, high);
    }
}

int searchRotated(int* nums, int numsSize, int target){
    int point = 0;

    if (numsSize == 0) {
        return -1;
    }

    if (nums[0] == target) {
        return 0;
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
        return dichotomySearch(nums, target, 0, point);
    } else {
        return dichotomySearch(nums, target, point + 1, numsSize - 1);
    }
}