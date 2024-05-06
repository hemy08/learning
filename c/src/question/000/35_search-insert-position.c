/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 35. 搜索插入位置
 * link: https://leetcode-cn.com/problems/search-insert-position/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

int searchInsert(int* nums, int numsSize, int target)
{
    if ((numsSize <= 0) || (nums == NULL)) {
        return 0;
    }
    
    if (nums[0] >= target) {
        return 0;
    }
    
    if (nums[numsSize -1] < target) {
        return numsSize;
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            return i;
        }

        if ((nums[i] < target) && (nums[i+1] >= target)) {
            return i+1;
        }
    }

    return 0;
}
/*
 * 优化
 */
int searchInsert2(int* nums, int numsSize, int target)
{
    int i;

    for (i = 0; i < numsSize; i++) {
        if (nums[i] >= target) {
            return i;
        }
    }

    return numsSize;
}


/*
 * 二分法查找
 */
int binarySearchInsert(int *nums, int key, int low, int high)
{
    int mid;
    if (low > high) {
        if (nums[low] > key) {
            return low;
        }
        return high;
    }

    mid = low + (high - low) / 2;
    if (nums[mid] == key) {
        return mid;
    } else if (nums[mid] > key) {
        if (nums[mid - 1] < key) {
            return mid;
        }
        return binarySearchInsert(nums, key, low, mid -1);
    } else {
        return binarySearchInsert(nums, key, mid + 1, high);
    }
}

int searchInsert3(int* nums, int numsSize, int target)
{
    if ((numsSize <= 0) || (nums == NULL)) {
        return 0;
    }

    if (nums[0] >= target) {
        return 0;
    }

    if (nums[numsSize -1] < target) {
        return numsSize;
    }

    return binarySearchInsert(nums, target, 0, numsSize);
}