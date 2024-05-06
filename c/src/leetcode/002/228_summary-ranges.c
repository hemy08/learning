/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 228. 汇总区间
 * link: https://leetcode-cn.com/problems/summary-ranges/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/6/15.
 */
#include "public.h"
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_ARR_NUM 128
#define MAX_STR_LEN 32
char ** summaryRanges(int* nums, int numsSize, int* returnSize){
    int num_arr[MAX_ARR_NUM][2] = {{0}};
    char **result = NULL;
    int count = 0;
    int start, end;

    if ((nums == NULL) || (numsSize == 0)) {
        *returnSize = 0;
        return NULL;
    }

    start = nums[0];
    end = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == (end + 1)) {
            end = nums[i];
            continue;
        }

        num_arr[count][0] = start;
        num_arr[count][1] = end;
        count++;

        start = nums[i];
        end = nums[i];
    }

    num_arr[count][0] = start;
    num_arr[count][1] = end;
    count++;

    *returnSize = count;
    result = (char**)malloc(sizeof(char*) * count);
    for (int i = 0; i < count; i++) {
        result[i] = (char*)malloc(sizeof(char) * MAX_STR_LEN);
        if (num_arr[i][0] == num_arr[i][1]) {
            sprintf(result[i], "%d", num_arr[i][0]);
        } else {
            sprintf(result[i], "%d->%d", num_arr[i][0], num_arr[i][1]);
        }
    }

    return result;
}