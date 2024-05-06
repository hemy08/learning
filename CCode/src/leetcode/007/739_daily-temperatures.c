/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 739. 每日温度
 * link: https://leetcode-cn.com/problems/daily-temperatures/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/12/2.
 */

#include "public.h"

int* dailyTemperatures(int* T, int TSize, int* returnSize)
{
    for (int i = 0; i < TSize; i++) {
        int pos = 0;
        for (pos = i + 1; pos < TSize; pos++) {
            if (T[pos] > T[i]) {
                break;
            }
        }

        T[i] =  (pos != 0) ? (pos - i) : 0;
    }
    *returnSize = TSize;
    return T;
}