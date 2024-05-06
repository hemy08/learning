/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 231. 2的幂
 * link: https://leetcode-cn.com/problems/power-of-two/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/7/13.
 */

#include "public.h"

bool isPowerOfTwo(int n)
{
    int tmp = 0;
    if (n == 0) {
        return false;
    }

    if (n == 1) {
        return true;
    }

    while(n != 1) {
        tmp = n % 2;
        if (tmp != 0) {
            return false;
        }
        n /= 2;
    }

    return true;
}