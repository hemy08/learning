/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 1165. 单行键盘
 * link: https://leetcode-cn.com/problems/single-row-keyboard/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

int map[26];

int calculateTime(char * keyboard, char * word)
{
    int i, j, len, lastPos, sum;
    len = strlen(word);
    lastPos = 0;
    sum = 0;
    for (i = 0; i < 26; i++) {
        map[keyboard[i] - 'a'] = i;
    }
    for (i = 0; i < len; i++) {
        sum = sum + abs(map[word[i] - 'a'] - lastPos);
        lastPos = map[word[i] - 'a'];
    }
    return sum;
}