/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description:
 * link:
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2021/8/31.
 */

#include "public.h"

int* compForSingleNumber(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int singleNumber(int* nums, int numsSize){
    if (numsSize %2 == 0) {
        return 0;
    }

    int numa = 0;
    int numb = 0;

    qsort(nums,numsSize,sizeof(int),compForSingleNumber);
    for (int i = 0; i < numsSize - 1; i++) {
        numa += nums[i++];
        numb += nums[i];
    }
    numa += nums[numsSize - 1];

    return numa - numb;
}

int singleNumberBitwise(int* nums, int numsSize){
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result = result ^ nums[i];
    }
    return result;
}