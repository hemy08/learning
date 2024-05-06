/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 10. 正则表达式匹配
 * link: https://leetcode-cn.com/problems/regular-expression-matching/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/6/20.
 */
#include "public.h"

bool isMatchRegular(char *s, char *p)
{
    if (s == NULL) {

    }

    if (p == NULL) {
        return false;
    }

    while (*s != '\0') {
        if (*p == '\0') {
            return false;
        }
        if (*s == *p) {
            s++;
            p++;
            continue;
        }

        if (*p == '.') {
            s++;
            p++;
            continue;
        }

        if (*p == '*') {
            // *(p - 1) 重复
            if (*s == *(p - 1)) {
                s++;
                continue;
            }
            // .*
            if (*(p - 1) == '.') {
                s++;
                continue;
            }
            // 不重复的时候,p后移
            p++;
            if (*s == *p) {
                s++;
                p++;
                continue;
            }

            // 不相同，说明匹配不上
            return false;
        }
    }

    if (*p == '\0') {
        return true;
    }

    return false;
}

// char boolStr[2][6] = {"false", "true"};
/*
void main()
{
    char s[100] = "aa";
    char p[100] = "a*";

    bool result = isMatch(s, p);

    printf("%s\n", boolStr[result]);
}*/
