/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 1. 两数之和
 * link: https://leetcode-cn.com/problems/two-sum/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    static int out[2]={0};
    int num1,num2,i,j = 0;

    for(i = 0; i < (numsSize-1); i++) {
        num1 = nums[i];
        num2 = target - num1;
        for(j = (i+1); j < numsSize; j++) {
            if(nums[j] == num2) {
                out[0] = i;
                out[1] = j;
                *returnSize = 2;
                return out;
            }
        }
    }

    return NULL;
}