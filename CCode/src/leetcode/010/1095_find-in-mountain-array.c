/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 1095. 山脉数组中查找目标值
 * link: https://leetcode-cn.com/problems/find-in-mountain-array/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

/**
 * *********************************************************************
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * int get(MountainArray *, int index);
 * int length(MountainArray *);
 */

/*
 * 山脉数组  array = [1,2,3,4,5,3,1]
 */
/**
 * *********************************************************************
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * int get(MountainArray *, int index);
 * int length(MountainArray *);
 */

#define MAX_MOUNT_LEN 10000
#define TYPE_LEFT 1
#define TYPE_RIGHT 2

int binarySearchMountain(MountainArray* mountainArr, int low, int high, int key, int type)
{
    if (low > high) {
        return -1;
    }

    int mid = (low + high + 1) / 2;
    int ai = get(mountainArr, mid);

    //printf("low %d, high %d, ai %d\n", low, high, ai);
    if (ai == key) {
        return mid;
    }

    if (((ai < key) && (type == TYPE_LEFT)) || ((ai > key) && (type == TYPE_RIGHT))) {
        return binarySearchMountain(mountainArr, mid + 1, high, key, type);
    } else {
        return binarySearchMountain(mountainArr, low, mid - 1, key, type);
    }

    return -1;
}

int findMountainPeak(MountainArray* mountainArr, int low, int high)
{
    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2;
    int a1 = get(mountainArr, mid - 1);
    int ai = get(mountainArr, mid);
    int a2 = get(mountainArr, mid + 1);

    if (a1 < ai) {
        if (ai > a2) {
            return mid;
        }
        return findMountainPeak(mountainArr, mid, high);
    } else {
        return findMountainPeak(mountainArr, low, mid);
    }

    return -1;
}

int findInMountainArray(int target, MountainArray* mountainArr) {
    int arrSize = length(mountainArr);

    if (arrSize < 3) {
        return -1;
    }

    if (arrSize > MAX_MOUNT_LEN) {
        return -1;
    }

    // 二分法找到脉峰 A[i-1] < A[i] > A[i+1]
    int peak = findMountainPeak(mountainArr, 0, arrSize - 1);
    if (peak == -1) {
        return -1;
    }
    //printf("peak %d\n", peak);

    // // 二分法查找，先查左侧山脉，后查右侧山脉，左侧是升序，右侧是降序，所以二分法查找有差异
    int find = binarySearchMountain(mountainArr, 0, peak, target, TYPE_LEFT);
    if (find == -1) {
        printf("right\n");
        find = binarySearchMountain(mountainArr, peak, arrSize - 1, target, TYPE_RIGHT);
    }

    return find;
}