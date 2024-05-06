/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 392. 判断子序列
 * link: https://leetcode-cn.com/problems/is-subsequence/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */
#include "public.h"

bool isSubsequence(char * s, char * t)
{
    char *pFind = t;
    char *pEnd = NULL;

    if ((s == NULL) || (strlen(s) == 0)) {
        return true;
    }

    if ((t == NULL) || (strlen(t) == 0)) {
        return false;
    }
    
    pEnd = s + strlen(s);
    while (pFind != NULL) {
        pFind = strchr(pFind,*s);
        if (pFind != NULL) {
            s++;
            if (s > pEnd) {
                return true;
            }
        } else {
            return false;
        }

        pFind++;
    }
    
    // t找到结尾还是没找全，则返回false
    if (s < pEnd) {
        return false;
    }

    return true;
}


bool isSubsequence2(char * s, char * t)
{
    char *ps_s = s;
    char *pt_s = t;
    char *ps_end = s + strlen(s);
    char *pt_end = t + strlen(t);

    while ((ps_s != ps_end) && (pt_s != pt_end)) {
        if (*ps_s == *pt_s) {
            ps_s++;
        }
        pt_s++;
    }

    if (ps_s == ps_end) {
        return true;
    }

    return false;
}

bool isSubsequence3(char * s, char * t)
{
    int lent = (int)strlen(t);
    int lens = (int)strlen(s);
    char *start = s;


    for (int i = 0; i < lent; i++) {
        if (t[i] == *start) {
            *start++;
        }

        if (start >= (s + lens)) {
            return true;
        }
    }

    if (start != (s + lens)) {
        return false;
    }

    return true;
}