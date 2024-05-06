/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 27. 移除元素
 * link: https://leetcode-cn.com/problems/remove-element/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

int removeElement(int* nums, int numsSize, int val){
    int count = 0;

    // 因为不需要考虑数组中超出新长度后面的元素，所以这里这里找到后面不同的，直接进行赋值。
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[count] = nums[i];
            count ++;
        }
    }

    return count;
}