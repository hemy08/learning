/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved. 
 * Description: 1151. 最少交换次数来组合所有的 1
 * link: https://leetcode-cn.com/problems/minimum-swaps-to-group-all-1s-together/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

int minSwaps(int* data, int dataSize){

    int count = 0;
    for (int i = 0; i < dataSize; ++i) {
        if (data[i] == 1) {
            ++count;
        }
    }

    int num = 0;
    for (int i = 0; i < count; ++i) {
        if (data[i] == 1) {
            ++num;
        }
    }

    int maxNum = num;
    int beg = 0;
    int end = count - 1;
    while (end < dataSize - 1) {
        if (data[beg] == 1) {
            --num;
        }
        ++beg;
        ++end;
        if (data[end] == 1) {
            ++num;
        }

        maxNum = GetMaxValue(maxNum, num);
    }

    return (count - maxNum);
}