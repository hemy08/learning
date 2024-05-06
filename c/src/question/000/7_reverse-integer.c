/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 7. 整数反转
 * link: https://leetcode-cn.com/problems/reverse-integer/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

#define MAX_INT_DIGITS_NUM 12
unsigned int g_nDigit[MAX_INT_DIGITS_NUM] = {0};

int reverse(int x)
{
    int temp = 0;
    int index = 0;

    // 获取各个位上的数字，反向存储
    for (int i = 1; i < MAX_INT_DIGITS_NUM; ++i) {
        g_nDigit[i] = x % 10;
        x /= 10;
        if (x == 0) {
            index = i;
            break;
        }
    }

    // 反向计算
    for (int i = 1; i <= index; ++i) {
        if ((temp > 214748364) || (temp < -214748364))
            return 0;
        temp *= 10;
        temp += g_nDigit[i];
    }

    return (int)temp;
}