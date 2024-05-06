/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 862. 和至少为 K 的最短子数组
 * link: https://leetcode-cn.com/problems/shortest-subarray-with-sum-at-least-k/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/9/19.
 */

#include "public.h"

int shortestSubarray(int* A, int ASize, int K)
{
    int *left = NULL;
    int *right = NULL;
    int count = 0;
    int min_num = ASize;

    if ((A == NULL) || (ASize == 0)) {
        return -1;
    }

    left = A;
    right = A;
    count = *left;

    while (right != '\0') {
        right++;
        if (right == '\0') {
            if (count <= K) {
                min_num = MIN_VAL(min_num, right - left);
            }

            return min_num;
        }

        count += *right;
        while (count <= K) {
            // 左侧减
            count -= *left;
            left++;
            min_num = MIN_VAL(min_num, right - left + 1);
        }
    }

    return min_num;
}
