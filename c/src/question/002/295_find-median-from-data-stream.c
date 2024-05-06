/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 295. 数据流的中位数
 * link: https://leetcode-cn.com/problems/find-median-from-data-stream/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/9/1.
 */

#include "public.h"

/*
#define MAX_NUMS_SIZE 19000

typedef struct {
    int nums[MAX_NUMS_SIZE + 1];
    int numsSize;
} MedianFinder;
*/

/** initialize your data structure here. */

MedianFinder* medianFinderCreate()
{
    MedianFinder *obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    if (obj == NULL) {
        return NULL;
    }

    obj->numsSize = 0;
    memset(obj->nums, 0, sizeof(obj->nums));

    return obj;
}

void printfMedianFinder(MedianFinder* obj)
{
    for (int i = 0; i < obj->numsSize; i++) {
        printf("%d ", obj->nums[i]);
    }
    printf("\n");
}

int medianFindInsertPosition(MedianFinder* obj, int num)
{
    int left = 0;
    int right = obj->numsSize - 1;

    while (left <= right) {
        int m = left + (right - left) / 2;
        if (obj->nums[m] == num) { // 找到了
            return m;
        } else if (obj->nums[m] > num) {
            left = m + 1;
        } else {
            right = m - 1;
        }
    }

    return left;
}

void medianFinderAddNum(MedianFinder* obj, int num)
{
    if ((obj == NULL) || (obj->numsSize >= MAX_NUMS_SIZE)) {
        return;
    }

    // 找到要插入的位置
    int pos = medianFindInsertPosition(obj, num);

    // pos之后的内容后移一个位置，移动obj->numsSize - pos个数
    memmove(&obj->nums[pos + 1], &obj->nums[pos], sizeof(int) * (obj->numsSize - pos));
    // 插入pos
    obj->nums[pos] = num;
    obj->numsSize++;

    // printfMedianFinder(obj);
}

double medianFinderFindMedian(MedianFinder* obj)
{
    int mid;
    double result = 0.0;

    if ((obj == NULL) || (obj->numsSize == 0)) {
        return 0.0;
    }

    mid = obj->numsSize / 2;
    // printf("mid %d, obj->numsSize %d, obj->nums[mid] %d\n", mid, obj->numsSize, obj->nums[mid]);
    if ((obj->numsSize % 2) == 0) {
        result = obj->nums[mid - 1] / 2.0 + obj->nums[mid] / 2.0;
    } else {
        result = (double)obj->nums[mid];
    }

    return result;
}

void medianFinderFree(MedianFinder* obj)
{
    free(obj);
    obj = NULL;
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);

 * double param_2 = medianFinderFindMedian(obj);

 * medianFinderFree(obj);
*/