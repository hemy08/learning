/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description:
 * link:
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2021/8/31.
 */

#include "public.h"

int* comp1(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

bool containsDuplicate(int* nums, int numsSize){
    qsort(nums,numsSize,sizeof(int), comp1);

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i-1]) {
            return true;
        }
    }

    return false;
}