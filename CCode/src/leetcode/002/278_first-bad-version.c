/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 278. 第一个错误的版本
 * link: https://leetcode-cn.com/problems/first-bad-version/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/8/14.
 */

#include "public.h"
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n)
{
    int low = 1;
    int high = n;
    int pos = (low / 2) + (high / 2);

    if (n == 1) {
        if (isBadVersion(1) == true) {
            return 1;
        }
    }

    while (high >= low) {
        // printf("low %d, high %d, pos %d \n", low, high, pos);
        if (isBadVersion(pos) == true) {
            if (isBadVersion(pos - 1) == false) {
                return pos;
            }
            high = pos - 1;
            pos = (low / 2) + (high / 2);
        } else {
            if (isBadVersion(pos + 1)) {
                return pos + 1;
            }
            low = pos + 1;
            pos = (low / 2) + (high / 2);
        }
    }

    return 0;
}