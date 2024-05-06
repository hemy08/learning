/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 剑指 Offer 11. 旋转数组的最小数字
 * link: https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/7/22.
 */

#include "public.h"

int compForMinArray(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int minArray(int* numbers, int numbersSize)
{
    qsort(numbers, numbersSize, sizeof(int), compForMinArray);

    return numbers[0];
}


/*
 * 二分法
 */
#define MIN_VAL(a,b) ((a) > (b) ? (b) : (a))

int binarySearch1(int *nums, int numsSize, int low, int high)
{
    if (low == high) {
        return nums[low];
    }

    if (low > high) {
        return MIN_VAL(nums[low], nums[high]);
    }

    int mid = low + (high - low) / 2;
    int a,b;
    if (nums[low] > nums[mid]) {
        a = binarySearch1(nums, numsSize, low + 1, mid);
    } else  {
        a = binarySearch1(nums, numsSize, low , mid - 1);
    }

    if (nums[high] > nums[mid]) {
        b = binarySearch1(nums, numsSize, mid, high - 1);
    } else  {
        b = binarySearch1(nums, numsSize, mid + 1, high);
    }

    return MIN_VAL(a, b);
}

int minArray1(int* numbers, int numbersSize)
{
    return binarySearch1(numbers, numbersSize, 0, numbersSize - 1);
}

/*
 * 二分法第二种
 */
#define MIN_VAL(a,b) ((a) > (b) ? (b) : (a))

int binarySearch2(int *nums, int numsSize, int low, int high)
{
    if (low >= high) {
        return MIN_VAL(nums[low], nums[high]);
    }

    if (nums[low] > nums[high]) {
        return binarySearch2(nums, numsSize, low + 1, high);
    } else  {
        return binarySearch2(nums, numsSize, low, high - 1);
    }
}

int minArray2(int* numbers, int numbersSize)
{
    return binarySearch2(numbers, numbersSize, 0, numbersSize - 1);
}

/*
 * 二分法官方的题解
 */
#define MIN_VAL(a,b) ((a) > (b) ? (b) : (a))

int binarySearch3(int *nums, int numsSize, int low, int high)
{
    if (high < 0) {
        return nums[low];
    }

    if (low >= high) {
        return MIN_VAL(nums[low], nums[high]);
    }

    int mid = low + (high - low) / 2;
    // 旋转数组，nums[mid] < nums[high]时，nums[mid + 1] ....nums[high] 都是大于nums[mid]的，所以要再low到mid这段找最小值
    if (nums[mid] < nums[high]) {
        return binarySearch3(nums, numsSize, low, mid);
    } else if (nums[mid] > nums[high]) { // nums[mid] > nums[high]时，nums[low] ....nums[mid] 都是大于nums[mid]的，所以要mid到high这段找最小值
        return binarySearch3(nums, numsSize, mid + 1, high);
    } else {
        return binarySearch3(nums, numsSize, low, high - 1);
    }
}
int minArray3(int* numbers, int numbersSize)
{
    return binarySearch3(numbers, numbersSize, 0, numbersSize - 1);
}