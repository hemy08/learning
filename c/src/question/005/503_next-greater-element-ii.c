/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 503. 下一个更大元素 II
 * link: https://leetcode-cn.com/problems/next-greater-element-ii/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/12/3.
 */

#include "public.h"

#define MAX_ELEMENTS_NUM 10001
int* nextGreaterElements(int* nums, int numsSize, int* returnSize)
{
    int stack[10001] = {-1};
    int top = 0;
    int flag = 0;

    int *result = (int*)malloc(sizeof(int) * numsSize);
    (void)memset(result, -1, sizeof(int)*numsSize);

    for (int i = 0; i < numsSize; i++) {
        // 比当前值小的值都出栈，然后填写对应的值
        while ((top != 0) && (nums[i] > nums[stack[top]])) {
            result[stack[top]] = nums[i];
            stack[top] = -1;
            top--;
        }

        // 当前值入栈
        if (flag == 0) {
            stack[++top] = i;
            if (i == (numsSize - 1)) {
                i = -1;
                flag = 1;
            }
        }
    }

    *returnSize = numsSize;
    return result;
}
