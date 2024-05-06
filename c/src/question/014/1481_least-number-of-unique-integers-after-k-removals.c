/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 1481. 不同整数的最少数目
 * link: https://leetcode-cn.com/problems/least-number-of-unique-integers-after-k-removals/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */
#include "public.h"

#define MAX_ARR_LEN 100001

int compForRegularMatch(const void *a, const void *b) {
    int m = *(int*)a;
    int n = *(int*)b;

    if (m > n) {
        return 1;
    }

    if (m == n) {
        return 0;
    }

    return -1;
}

int findLeastNumOfUniqueInts(int* arr, int arrSize, int k){
    int a[MAX_ARR_LEN]= {0};
    int count = 0;
    int flag = 0;

    if ((arr == NULL) || (arrSize == 0)) {
        return 0;
    }

    // 原数组排序
    qsort(arr, arrSize, sizeof(int), compForRegularMatch);

    // 对排序后的数组遍历，计算数字重复次数
    int number = arr[0];
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == number) {
            a[count]++;
            continue;
        }

        count++;
        a[count]++;
        number = arr[i];
    }
    count++;

    if (k == 0) {
        return count;
    }

    int reserve = k;
    int result = count;
    // 对个数排序
    qsort(a, count, sizeof(int), compForRegularMatch);
    for (int i = 0; i < count; i++) {
        if (a[i] < reserve) {
            reserve -= a[i];
            result--;
        } else if (a[i] == reserve) {
            result--;
            break;
        } else {
            break;
        }
    }

    return result;
}