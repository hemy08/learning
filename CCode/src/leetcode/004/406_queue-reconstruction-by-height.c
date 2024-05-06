/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 406. 根据身高重建队列
 * link: https://leetcode-cn.com/problems/queue-reconstruction-by-height/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */
#include "public.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define PEOPLE_INFO 2
int compTwoDimensionalArray(const void *a, const void *b) {
    int *pa = (int**)a;
    int *pb = (int**)b;
    // 身高相同，按照个数升序
    if (pa[0] == pb[0]) {
        return pa[1] - pb[1];
    }

    return pb[0] - pa[0];
}

void resultMove(int** people, int peopleSize, int k)
{
    int i,j;
    int tmpa[PEOPLE_INFO] = {0};
    int tmpb[PEOPLE_INFO] = {0};

    if ((peopleSize < k) || (people == NULL)) {
        return;
    }

    // 保存K的值，要填写到K+1位置
    tmpa[0] = people[k][0];
    tmpa[1] = people[k][1];

    for (i = k; i < peopleSize - 1; i++) {
        tmpb[0] = people[i + 1][0];
        tmpb[1] = people[i + 1][1];
        people[i + 1][0] = tmpa[0];
        people[i + 1][1] = tmpa[1];
        tmpa[0] = tmpb[0];
        tmpa[1] = tmpb[1];
    }

}
int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes)
{
    int **result = NULL;
    int i,j,k;
    if ((people == NULL) || (peopleSize == 0) || (peopleColSize == NULL)) {
        *returnSize = 0;
        return NULL;
    }

    qsort(people, peopleSize, sizeof(int*), compTwoDimensionalArray);
    result = (int**)malloc(sizeof(int*) * peopleSize);
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = peopleSize;

    for (i = 0; i < peopleSize; i++) {
        result[i] = (int*)malloc(sizeof(int) * PEOPLE_INFO);
        if (result[i] == NULL) {
            return NULL;
        }
        result[i][0] = 0;
        result[i][1] = 0;
    }

    for (i = 0; i < peopleSize; i++) {
        k = people[i][1];
        if (k > peopleSize) {
            return NULL;
        }
        // 将people[i]插入result[k]的位置
        resultMove(result, peopleSize, k);
        result[k][0] = people[i][0];
        result[k][1] = people[i][1];
    }

    *returnColumnSizes = (int *)malloc(sizeof(int) * peopleSize);
    for (int i = 0; i < peopleSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    return result;
}