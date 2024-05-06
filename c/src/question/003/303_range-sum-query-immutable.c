/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 303. 区域和检索 - 数组不可变
 * link: https://leetcode-cn.com/problems/range-sum-query-immutable/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

/*typedef struct {
    int sum;
} NumArray;*/


NumArray* numArrayCreate(int* nums, int numsSize)
{
    if (numsSize == 0) {
        return NULL;
    }
    NumArray* obj = (NumArray*)malloc((numsSize + 1) * sizeof(NumArray));
    if (obj == NULL) {
        return NULL;
    }

    memset(obj, 0, (numsSize + 1) * sizeof(NumArray));

    obj[0].sum = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        obj[i].sum = obj[i - 1].sum + nums[i];
    }

    return obj;
}

int numArraySumRange(NumArray* obj, int i, int j)
{
    if (obj == NULL) {
        return 0;
    }
    
    if (i == 0) {
        return obj[j].sum;
    }

    return obj[j].sum - obj[i - 1].sum;
}

void numArrayFree(NumArray* obj) {
    NumArray* tmpObj = obj;
    while (tmpObj != NULL) {
        free(tmpObj);
        obj ++;
        tmpObj = obj;
    }
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);

 * numArrayFree(obj);
*/