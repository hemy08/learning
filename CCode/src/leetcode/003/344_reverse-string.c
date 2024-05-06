/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 344. 反转字符串
 * link: https://leetcode-cn.com/problems/reverse-string/submissions/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/6/23.
 */

#include "public.h"

void reverseString(char* s, int sSize)
{
    char *c;
    if (s == NULL) {
        return;
    }

    // 奇数
    int max = sSize / 2;
    for (int i = 0; i < max; i++) {
        c = s[sSize - i - 1];
        s[sSize - i - 1] = s[i];
        s[i] = c;
    }
}