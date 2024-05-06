/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 922. 按奇偶排序数组 II
 * link: https://leetcode-cn.com/problems/sort-array-by-parity-ii/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/11/12.
 */

#include "public.h"

int* sortArrayByParityII(int* A, int ASize, int* returnSize)
{
    *returnSize = ASize;

    int *result = (int*)malloc(sizeof(int) * ASize);
    (void)memset(result, 0, sizeof(int)*ASize);

    int even = 0;
    int odd = 1;
    for (int i = 0; i < ASize; i++) {
        // 偶数
        if ((A[i] % 2) == 0) {
            result[even] = A[i];
            even += 2;
        } else { // 奇数
            result[odd] = A[i];
            odd += 2;
        }
    }

    return result;
}