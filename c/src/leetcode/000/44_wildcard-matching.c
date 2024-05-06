/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 44. 通配符匹配
 * link: https://leetcode-cn.com/problems/wildcard-matching/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/12/1.
 */

#include "public.h"

bool isMatchWildCardSolution1(char * s, char * p)
{
    char *start_p = p;
    char *start_s = s;
    while (*start_p != '\0') {
        if (*start_p == '*') {
            start_p++;
            // p结束了
            if (*start_p == '\0') {
                return true;
            }

            // 匹配*之后的字符，在s中找,从后往前找，最大匹配
            char *end = s + strlen(s);
            while (end != *s) {
                if (*end == *start_p) {
                    break;
                }
                *end--;
            }

            start_s = end;
            continue;
        }

        // 是？，s和p都后移
        if (*start_p == '?') {
            start_p++;
            start_s++;
            continue;
        }

        if (*start_s != *start_p) {
            return false;
        }
    }

    // p没结束，s结束了
    if (*start_s != '\0') {
        return false;
    }

    return true;
}
bool allStars(char* str, int left, int right) {
    for (int i = left; i < right; ++i) {
        if (str[i] != '*') {
            return false;
        }
    }
    return true;
}
bool charMatch(char u, char v) { return u == v || v == '?'; };

bool isMatchWildCardSolution2(char* s, char* p) {
    int len_s = strlen(s), len_p = strlen(p);
    while (len_s && len_p && p[len_p - 1] != '*') {
        if (charMatch(s[len_s - 1], p[len_p - 1])) {
            len_s--;
            len_p--;
        } else {
            return false;
        }
    }
    if (len_p == 0) {
        return len_s == 0;
    }

    int sIndex = 0, pIndex = 0;
    int sRecord = -1, pRecord = -1;
    while (sIndex < len_s && pIndex < len_p) {
        if (p[pIndex] == '*') {
            ++pIndex;
            sRecord = sIndex;
            pRecord = pIndex;
        } else if (charMatch(s[sIndex], p[pIndex])) {
            ++sIndex;
            ++pIndex;
        } else if (sRecord != -1 && sRecord + 1 < len_s) {
            ++sRecord;
            sIndex = sRecord;
            pIndex = pRecord;
        } else {
            return false;
        }
    }
    return allStars(p, pIndex, len_p);
}
