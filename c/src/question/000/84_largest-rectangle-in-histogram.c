/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 84. 柱状图中最大的矩形
 * link: https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/8/8.
 */

#include "public.h"

int getMaxArea(int* heights, int heightsSize, int pos)
{
    int count = 1;
    for (int i = pos + 1; i < heightsSize; i++) {
        if (heights[i] < heights[pos]) {
            break;
        }
        count++;
    }

    for (int i = pos - 1; i >= 0; i--) {
        if (heights[i] < heights[pos]) {
            break;
        }
        count++;
    }

    return heights[pos] * count;
}

int largestRectangleArea(int* heights, int heightsSize)
{
    int max = 0;
    int dp = 0;

    for (int i = 0; i < heightsSize; i++) {
        dp = getMaxArea(heights, heightsSize, i);
        max = GetMaxValue(max, dp);
    }

    return max;
}