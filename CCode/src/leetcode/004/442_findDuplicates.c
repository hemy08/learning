/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description:442. 数组中重复的数据
 * link:https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/12/4.
 */

#include "public.h"
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize)
{
    char *counts = (char*)malloc(sizeof(char) * (numsSize + 1));
    (void)memset(counts, 0, sizeof(char) * (numsSize + 1));

    int findNum = 0;
    int *result = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        counts[nums[i]]++;
        if (counts[nums[i]] >= 2) {
            result[findNum++] = nums[i];
        }
    }
    *returnSize = findNum;
    free(counts);
    return result;
}
