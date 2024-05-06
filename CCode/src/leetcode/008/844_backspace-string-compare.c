/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 844. 比较含退格的字符串
 * link: https://leetcode-cn.com/problems/backspace-string-compare/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/10/21.
 */

#include "public.h"

#define MAX_STR_LEN 202

void delBackSpace(char * input, char * output)
{
    int i = 0;

    while (*input != '\0') {
        if (*input != '#') {
            output[i] = *input;
            i++;
            input++;
            continue;
        }

        if (i > 0) {
            i--;
            output[i] = '\0';
        }
        input++;
    }
}

bool backspaceCompare(char * S, char * T)
{
    char s_tmp[MAX_STR_LEN];
    char t_tmp[MAX_STR_LEN];

    (void)memset(s_tmp, 0, MAX_STR_LEN);
    (void)memset(t_tmp, 0, MAX_STR_LEN);

    delBackSpace(S, s_tmp);
    delBackSpace(T, t_tmp);

    if (0 == strcmp(s_tmp, t_tmp)) {
        return true;
    }

    return false;
}