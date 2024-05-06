/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 
 * link: 
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/11/9.
 */

#include "public.h"

//
void OutPutArrays(int *nums, int numSize)
{
    printf("\n nums Begin: \t");
    for (int i = 0; i < numSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("nums End.\t\n");
}

int CountArrays(int *nums, int numSize)
{
    int count = 0;
    for (int i = 0; i < numSize; i++) {
        count += nums[i];
    }

    return count;
}

int compareFuncAscendingOrder(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int compareFuncDescendingOrder(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}

// 比较二维数组大小，升序
int compTwoDimensionalArrayAscendingOrder(const void *a, const void *b) {
    int *pa = *(int**)a;
    int *pb = *(int**)b;
    return pa[0] - pb[0];
}

// 比较二维数组大小，降序
int compTwoDimensionalArrayDescendingOrder(const void *a, const void *b) {
    int *pa = *(int**)a;
    int *pb = *(int**)b;
    return pb[0] - pa[0];
}

inline int CmpBsearch(const void *a, const void *b)    {
    char *src = *(char **)a;
    char *dst = *(char **)b;
    return strcmp(src, dst);
}

void example_bsearch()
{
    inline int Cmp(const void *a, const void *b)    {
        char *src = *(char **)a;
        char *dst = *(char **)b;
        return strcmp(src, dst);
    }

    char *retStr[3] = {"abc", "bbc", "cbc"};
    char *new = "bbc";
    int count = 3;
    char **find = bsearch(&new, retStr, count, sizeof(char *), CmpBsearch);
}

void example_strtok_s()
{
    char reviews[] = "java python cpp";
    char *nextToken = NULL;
    char *token = NULL;
    char *seps = " ";
    token = strtok_s(reviews, seps, &nextToken);
    while (token != NULL) {
        printf("%s\r\n", token);
        token = strtok_s(NULL, seps, &nextToken);
    }
}
