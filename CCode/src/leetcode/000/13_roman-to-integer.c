/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 13. 罗马数字转整数
 * link: https://leetcode-cn.com/problems/roman-to-integer/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

int romanToInt(char * s)
{
    char *psStr = s;
    unsigned int uiResult = 0;

    while((psStr != NULL) && (*psStr != '\0')) {
        switch (*psStr) {
            case 'I':
                psStr ++;
                if(*psStr == 'V') {
                    uiResult += 4;
                    psStr ++;
                } else if(*psStr == 'X') {
                    uiResult += 9;
                    psStr ++;
                } else {
                    uiResult += 1;
                }
                break;
            case 'V':
                uiResult += 5;
                psStr ++;
                break;
            case 'X':
                psStr ++;
                if(*psStr == 'L') {
                    uiResult += 40;
                    psStr ++;
                } else if(*psStr == 'C') {
                    uiResult += 90;
                    psStr ++;
                } else {
                    uiResult += 10;
                }
                break;
            case 'L':
                uiResult += 50;
                psStr ++;
                break;
            case 'C':
                psStr ++;
                if(*psStr == 'D') {
                    uiResult += 400;
                    psStr ++;
                } else if(*psStr == 'M') {
                    uiResult += 900;
                    psStr ++;
                } else {
                    uiResult += 100;
                }
                break;
            case 'D':
                uiResult += 500;
                psStr += 1;
                break;
            case 'M':
                uiResult += 1000;
                psStr += 1;
                break;
        }
    }

    return (int)uiResult;
}

