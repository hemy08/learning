/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description:
 * link:
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2021/8/31.
 */

#include "public.h"

void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    if (k == 0) {
        return;
    }

    int times = numsSize - k;
    int newArr[numsSize];

    // 保存前段
    for (int i = 0; i < times; i++) {
        newArr[i] = nums[i];
    }

    // 后段赋值到前段，赋值K个字符
    for (int i = 0; i < k; ++i) {
        nums[i] = nums[times + i];
    }

    // 之前保存的前段赋值给后段，
    for (int i = 0; i < times; ++i) {
        nums[i + k] = newArr[i];
    }
}

void rotateOne(int* nums, int numsSize) {
    int tmp = nums[0];
    for (int i = 1; i < numsSize; i++) {
        nums[i - 1] = nums[i];
    }

    nums[numsSize - 1] = tmp;
}


void rotateNewArray(int* nums, int numsSize, int k) {
    k = k % numsSize;
    if (k == 0) {
        return;
    }

    int newArr[numsSize];
    for (int i = 0; i < numsSize; ++i) {
        newArr[(i + k) % numsSize] = nums[i];
    }
    for (int i = 0; i < numsSize; ++i) {
        nums[i] = newArr[i];
    }
}