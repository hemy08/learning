/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description:
 * link:
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2021/8/31.
 */

#include "public.h"

int* compForSingleNumber(const void *a, const void *b) {
    return (int *) (*(int *) b - *(int *) a);
}

int singleNumber1(int* nums, int numsSize){
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

// 数组方法，排序，然后利用栈的方法
int comp_SingleNumber2(const void *a, const void *b) {
    if (*(int*)a > *(int*)b) {
        return 1;
    }
    return -1;
}

int singleNumber2(int* nums, int numsSize) {
    unsigned int top = 0;
    if ((numsSize == 0) || (numsSize %2 == 0)) {
        return 0;
    }

    if (numsSize == 1) {
        return nums[0];
    }
    qsort(nums, numsSize, sizeof(int), comp_SingleNumber2);

    int* stack = (int*)malloc(4 * sizeof(int));
    if (stack == NULL) {
        return 0;
    }
    (void)memset(stack, 0, 4 * sizeof(int));
    stack[top] = -100000000;

    for (int i = 0; i < numsSize; i++) {
        if (stack[top] == nums[i]) {
            top--;
            continue;
        }
        top++;
        stack[top] = nums[i];
    }
    if (top > 1) {
        return 0;
    }
    int result = stack[1];
    free(stack);
    return result;
}

int singleNumberBitwise(int* nums, int numsSize){
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result = result ^ nums[i];
    }
    return result;
}