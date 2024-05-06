/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 38. 外观数列
 * link: https://leetcode-cn.com/problems/count-and-say/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

#define MAX_COUNT_NUM 30

char g_acCount[MAX_COUNT_NUM + 1][10240] = {
        {"0"},
        {"1"},
        {"11"},
        {"21"},
        {"1211"},
        {"111221"},
        {0},
};

#define CASE_PROC(ptr,chr,src,dest)                     \
    if ((*ptr) == chr) {                              \
        if ((*(ptr+1))  == chr) {                     \
            if ((*(ptr+2))  == chr) {                 \
                strcat(dest,"3");                   \
                strcat(dest,src);             \
                ptr += 3;                           \
            } else {                                \
                strcat(dest,"2");                   \
                strcat(dest,src);             \
                ptr += 2;                           \
            }                                       \
        } else {                                    \
            strcat(dest,"1");                           \
            strcat(dest,src);                     \
            ptr += 1;                                   \
        }                                               \
        continue;                                       \
    }


char* GetCount(int n)
{
    char *pcData = g_acCount[n-1];
    char *pcBegin = pcData;

    if (n > MAX_COUNT_NUM) {
        return NULL;
    }

    if (0 == g_acCount[n][0]) {
        (void)GetCount(n-1);
    }

    memset(g_acCount[n],0, sizeof(g_acCount[n]));
    while (*pcBegin !=  '\0') {
        CASE_PROC(pcBegin,0x31,"1",g_acCount[n])
        CASE_PROC(pcBegin,0x32,"2",g_acCount[n])
        CASE_PROC(pcBegin,0x33,"3",g_acCount[n])
    }

    return g_acCount[n];
}

char* countAndSay(int n) {
    if (0 != g_acCount[n][0]) {
        return &(g_acCount[n][0]);
    }
    
    return GetCount(n);
}

#define MAX_RES_SIZE 5000
char result[5000] = {0};

char* countAndSayRecursion(int n) {
    if (n == 1) {
        char *res = malloc(2 * sizeof(char));
        (void) memset(res, 0, 2 * sizeof(char));
        res[0] = '1';
        return res;
    }

    char *str = countAndSayRecursion(n - 1);
    int len = strlen(str);
    char strTmp[MAX_RES_SIZE] = {0};
    int index = 0;
    int begin = 0;
    while (begin < len) {
        int count = 0;
        for (int j = begin; j < len; j++) {
            if (str[begin] != str[j]) {
                break;
            }

            count++;
        }
        strTmp[index++] = count+'0';
        strTmp[index++] = str[begin];
        begin += count;
    }

    (void) memset(result, 0, MAX_RES_SIZE);
    memcpy(result, strTmp, index);
    return result;
}



void testCountAndSay()
{
    for (int i = 1; i <= 30; i++) {
        char *res = countAndSayRecursion(i);
        printf("%d, len %d, %s\n", i, strlen(res),res);
    }
}