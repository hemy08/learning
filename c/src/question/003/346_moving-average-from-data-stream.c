/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 346. 数据流中的移动平均值
 * link: https://leetcode-cn.com/problems/moving-average-from-data-stream/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/9/1.
 */

#include "public.h"

/*typedef struct {
    int size;
    int *nums;
    int numsSize;
} MovingAverage;*/

/** Initialize your data structure here. */

MovingAverage* movingAverageCreate(int size)
{
    MovingAverage* obj = (MovingAverage*)malloc(sizeof(MovingAverage));
    obj->size = size;
    obj->numsSize = 0;
    obj->nums = (int*)malloc(sizeof(int) * (size + 1));
    memset(obj->nums, 0, sizeof(int) * (size + 1));
    return obj;
}

/*
 * 耗时要另外一个多
 * */
double movingAverageNext(MovingAverage* obj, int val)
{
    int pos, max;
    double total = 0;

    if (obj == NULL) {
        return 0.0;
    }

    pos = obj->numsSize % obj->size;
    obj->nums[pos] = val;
    obj->numsSize++;
    max = MIN_VAL(obj->numsSize, obj->size);

    // printf("pos %d, max %d\n", pos, max);
    for (int i = 0; i < max; i++) {
        total += obj->nums[i];
    }

    return total / max;
}

void movingAverageFree(MovingAverage* obj)
{
    free(obj->nums);
    free(obj);
    obj = NULL;
}

/**
 * Your MovingAverage struct will be instantiated and called as such:
 * MovingAverage* obj = movingAverageCreate(size);
 * double param_1 = movingAverageNext(obj, val);

 * movingAverageFree(obj);
*/

// #define MAX_SIZE 20480

#define MIN_VAL(a,b) ((a) > (b) ? (b) : (a))

/*typedef struct {
    int size;
    int nums[MAX_SIZE + 1];
    int numsSize;
} MovingAverageArray;*/

MovingAverageArray* movingAverageCreateWithArray(int size)
{
    MovingAverageArray* obj = (MovingAverageArray*)malloc(sizeof(MovingAverageArray));
    obj->size = size;
    obj->numsSize = 0;
    memset(obj->nums, 0, sizeof(obj->nums));
    return obj;
}

double movingAverageNextWithArray(MovingAverageArray* obj, int val)
{
    int start = 0;
    double total = 0;
    if (obj == NULL) {
        return 0.0;
    }

    obj->nums[obj->numsSize] = val;
    obj->numsSize++;
    if (obj->numsSize > obj->size) {
        start = obj->numsSize - obj->size;
    }

    for (int i = start; i < obj->numsSize; i++) {
        total += obj->nums[i];
    }

    if (obj->numsSize < obj->size) {
        return total / obj->numsSize;
    }

    return total / obj->size;
}

void movingAverageFreeArray(MovingAverage* obj)
{
    free(obj);
    obj = NULL;
}